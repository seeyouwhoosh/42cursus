# Inception
## Preparar los directorios  

```
inception/  
├── Makefile  
├── secrets/  
│   ├── db_password.txt  
│   └── db_root_password.txt  
└── srcs/  
    ├── docker-compose.yml  
    ├── .env  
    └── requirements/  
        ├── mariadb/  
        │   ├── Dockerfile  
        │   ├── conf/  
        │   └── tools/  
        ├── nginx/  
        │   ├── Dockerfile  
        │   ├── conf/  
        │   └── tools/  
        └── wordpress/  
            ├── Dockerfile  
            ├── conf/  
            └── tools/  
```
Comando para facilitar la vida, gracias
```sh
mkdir -p inception/{secrets,srcs/requirements/{mariadb/{conf,tools},nginx/{conf,tools},wordpress/{conf,tools}}} \
&& touch inception/Makefile inception/secrets/{db_password.txt,db_root_password.txt} inception/srcs/{docker-compose.yml,.env} inception/srcs/requirements/{mariadb,nginx,wordpress}/{Dockerfile,.dockerignore}
```

## Instalar Docker

```sh
# Add Docker's official GPG key:
sudo apt update
sudo apt install ca-certificates curl
sudo install -m 0755 -d /etc/apt/keyrings
sudo curl -fsSL https://download.docker.com/linux/debian/gpg -o /etc/apt/keyrings/docker.asc
sudo chmod a+r /etc/apt/keyrings/docker.asc

# Add the repository to Apt sources:
sudo tee /etc/apt/sources.list.d/docker.sources <<EOF
Types: deb
URIs: https://download.docker.com/linux/debian
Suites: $(. /etc/os-release && echo "$VERSION_CODENAME")
Components: stable
Signed-By: /etc/apt/keyrings/docker.asc
EOF

sudo apt update

# Install the Docker packages
sudo apt install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```
  
Ejecutar `docker run hello-world` para ver si funciona  
  
```sh
# List images
docker images

# List running containers
docker ps

# List all containers (including stopped)
docker ps -a
```
  
**How Docker and docker compose work** 

**Docker** es un software con el que puedes crear mini máquinas virtuales (solo a nivel de app) llamados contenedores.  
  
Los **contenedores** contienen todo lo necesario (las dependencias en su versión correcta, las variables de entorno necesarias…) para correr la app.  
  
Para correr las apps en los contenedores, necesitas un ejecutable con todas las dependencias, el programa y tal. Y para compilar el ejecutable, llamado **imagen**, tenemos que hacer un Dockerfile.   
  
```sh
# Comandos relevantes
docker build
docker run

# Ejemplo
docker run -d -p 8080:80 --name my-nginx nginx
# -d: detached, corre en segundo plano
# -p: puerto público:privado
```
  
**Docker-compose** es una herramienta para correr varios contenedores de manera más rápida (de lo contrario, habría que correr `docker build` y `docker compose` para cada aplicación. Se aplica el comando `docker-compose` sobre un archivo .yml. YAML es [whitespace-sensitive y no acepta tabs](https://fixed.docs.upsun.com/learn/overview/yaml/what-is-yaml.html). 

La plantilla del docker-compose de este proyecto (no todos los campos son necesarios):

```yml
services:
  mariadb: 
    build: # para hacer que docker-compose buildee la imagen antes de correr
      context: # el dockerfile suele estar aquí, solo basta poner esto; si no, se usa para buscar sus archivos dependientes
      dockerfile: # el dockerfile
    image: #formato: imagen:versión
    ports:
      #- "público:privado"
    container_name: 
    depends_on:
      #- wordpress
    networks:
    volumes: # Si quieres que los datos persistan incluso cuando el contenedor no está corriendo
      - mariadb_data:/var/www/html
    env_file: #alternativa para usar env (${VAR}): "environment:"
      .env
    secrets:
      #-db_passwords
    restart: on-failure 

volumes: 
  mariadb_data:
    driver:
    driver_opts:
      type:
      o: 
      device: 

secrets: # Docker tiene su propio gestor de contraseñas e información sensible
  #db_passwords:
    #file: .txt
```

* [Infomación sobre restart](https://github.com/compose-spec/compose-spec/blob/main/spec.md#restart)

**The benefit of Docker compared to VMs**  

| Aspect         | Docker Containers    | Virtual Machines    |
| -------------- | -------------------- | ------------------- |
| Resource Usage | Share host OS kernel | Each VM has full OS |
| Startup Time   | Seconds              | Minutes             |
| Memory         | MB                   | GB                  |
  
Por ejemplo, si en una máquina virtual quisieras correr un software que necesita Python 3.14 y otro que necesita Python 3.12, lo corres cada uno en su docker con sus dependencias correspondientes y no se matan entre sí.  

## Docker network
![dockernetwork](image.png)
Para conectar contenedores entre sí, requerimos que estén en la misma network. Docker, como añade un nivel de abstracción y tal, tiene tipos de network dependiendo de lo que queramos:
* **Bridge**: A bridge network is the **default network type** when you install Docker. It allows containers to communicate with each other and the host machine, but provides no access to the outside world, aunque se puede conseguir mediante NAT (traducción de red). Red privada virtual
* **Host**: A host network uses the host machine's network stack and provides no isolation between the host and the container. Es decir, usa los puertos del host como si fueran propios
* **Overlay**: An overlay network allows containers running on different Docker hosts to communicate with each other.
* **Macvlan**: A Macvlan network allows a container to have its own IP address (y MAC, es decir, funciona como si fuera una máquina independiente) on the same subnet as the host machine

Crearemos nuestro custom network (que es del tipo bridged) porque
1. Los contenedores solo se comunican mediante la dirección IP (podemos hacerlo por nombres)
2. No hay Dynamic Name System, es decir, si asociamos un nombre a una dirección IP, cuando cambie, este no cambiará la IP asociada
3. Menos seguro en general porque están todos los contenedores amontonados en una misma red

SO...
```sh
# Create a custom network
docker network create inception-network

# List networks
docker network ls

# Inspect the network
docker network inspect inception-network
```

Y como los contenedores van a estar en esa network, lo declaramos en nuestro docker-compose.yml.

```yml
networks:
  inception-network:
    driver: bridge
```

## MariaDB

MariaDB es una herramienta para gestionar bases de datos relacionales (lo que sea que sea eso), en fin, se usa para estructurar información. Es un fork de MySQL, sigue siendo muy compatible.

**Dockerfile**
```Dockerfile
# Imagen base que usaremos para construir la imagen de la aplicación (penúltima versión: 11, bullseye). Más ejemplos de bases: python, w
FROM debian:bullseye

RUN apt update
RUN apt install -y mariadb-server mariadb-client

# chown changes ownership -R recursivamente de mysql del grupo mysql para que pueda modificar /var/run/mysqld
RUN mkdir -p /var/run/mysqld /var/lib/mysql \
    && chown -R mysql:mysql /var/run/mysqld /var/lib/mysql  \
    && chmod 777 /var/run/mysqld

EXPOSE 3306

COPY conf/mariadb.conf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY conf/dump.sql /usr/local/bin/
COPY conf/mariadb.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/mariadb.sh

ENTRYPOINT [ "/usr/local/bin/mariadb.sh" ]
CMD ["mysqld"]
```

**Configuration file**

Tras buscar en /etc/mysql, en my.cnf, he puesto las configuraciones que he encontrado que parecen útiles
```ini
[mysqld]
bind-address = 0.0.0.0 # escucha todas las network interfaces
port = 3306
skip-networking = false # habilita escuchar desde puerto y aceptar conexiones
socket = /var/run/mysqld/mysqld.sock # permite a una aplicación conectarse a una base de datos para enviar consultas y recibir resultados
datadir = /var/lib/mysql # directorio de all database files
# pid-file = /var/run/mysqld/mysqld.pid
```

**Initialization script**
```sh
#!/bin/bash

set -e

# Initialize MySQL data directory if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null
fi

mariadb -u root << EOF
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';

ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL ON *.* TO 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';

FLUSH PRIVILEGES;
EOF

mariadb -u root ${MYSQL_DATABASE} < /usr/local/bin/dump.sql

exec "$@"
```

## Nginx
Nginx es:
* **Servidor web**: almacena los archivos de un sitio web (.html, .css, imágenes y así) y los envía a los usuarios a través de internet mediante el protocolo HTTP/HTTPS 
* **Reverse proxy**: es un servidor intermediario entre el cliente y los servidores internos; por ejemplo, si tienes muchos servidores de minecraft, puedes hacer que pasen todos tengan el mismo dominio (patata.serv1.com, patata.sev2.com...) y que el proxy se encargue de redirigirlos a su sitio correspondiente dentro de tu casa.
* **Almacenar caché**
* **Load balancing**: Distribuye eficientemente el tráfico entrante entre múltiples servidores backend
* **Protección ante ataques**: Con un proxy inverso instalado, un sitio o servicio web no necesita revelar nunca la dirección IP de su(s) servidor(es) de origen

Puedes configurar Nginx para que use distintos protocoles de red (SSL, y en nuestro caso, TLS)

TLS (**Transport Layer Security**) es un protocolo de seguridad de red. TLS works by using public key encryption to establish a secure connection between two parties. When a client wants to communicate with a server using TLS, the client and server exchange a series of messages to establish a secure connection. This process includes the exchange of digital certificates and the negotiation of encryption keys. Once the connection is established, the client and server can communicate securely over the internet.

Para implementar el TLS (también el SSL), se usa **OpenSSL**, que es gratis y open source.

**Dockerfile**
```Dockerfile
FROM debian:bullseye

# Corre comandos durante el proceso de build
RUN apt update
RUN apt install -y nginx openssl
RUN mkdir -p /etc/nginx/ssl

# Informa qué puerto está escuchando el contenedor cuando se ejecute
EXPOSE 443

# Copia los archivos y directorios de ARG1 a ARG2
COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/nginx_start.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/nginx_start.sh

# Corre el ejecutable cuando inicia el contenedor
ENTRYPOINT [ "/usr/local/bin/nginx_start.sh" ]
```

Ahora, en `/nginx/tools` creamos el archivo `nginx_start.sh` para que genere el coso el certificado

**Initialization script**
```sh
#!/bin/bash

## Por si ocurre algún error
set -e

if [ ! -f /etc/ssl/certs/nginx.crt ]; then
    echo "Nginx: Generating self-signed SSL certificate"

    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt \
    -subj "/C=ES/ST=Bizkaia/L=Urduliz/O=42/CN=xwu.42.fr"

    chmod 600 /etc/nginx/ssl/nginx.key
    chmod 644 /etc/nginx/ssl/nginx.crt

    echo "Nginx: Certificate generated at /etc/nginx/ssl/"

else
    echo "Nginx: SSL certificate already exists"

fi

echo "Starting Nginx..."
exec nginx -g "daemon off;"
```

Explicación de la línea rara esta de `openssl req` , que genera el certificado:
* `-x509`: certificado autofirmado
* `-nodes`: no DES encryption, no hay contraseña
* `-days 365`: válido por 365 días
* `-newkey rsa:2048`: clave tipo rsa, 2048 bits
* `-keyout`: dónde guardar la clave privada (por eso solo el usuario tiene permisos 600)
* `-out`: dónde guardar el certificado público (644, just reading for others)
* `-subj`: información del certificado, `"/C=COUNTRY/ST=State/L=LOCALIDAD/O=Organization/CN=Domain_name"`

**Configuration file**
```ini
server {
    listen 443 ssl;
    listen [::]:443 ssl;
    server_name xwu.42.fr;

    ssl_certificate /etc/ssl/certs/nginx.crt;
    ssl_certificate_key /etc/ssl/private/nginx.key;
    ssl_protocols TLSv1.3;

    index index.php;
    root /var/www/html;
    location / {
        try_files $uri $uri/ /index.php$is_args$args;
    }
    location ~ \.php$ {
        try_files $uri =404;
        fastcgi_split_path_info ^(.+\.php)(/.+)$;
        fastcgi_pass wordpress:9000;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
        fastcgi_param PATH_INFO $fastcgi_path_info;
        fastcgi_read_timeout 300;
    }
}
``` 

## Wordpress


**Dockerfile**
```Dockerfile
FROM debian:bullseye

RUN apt update
RUN apt install -y php8.2-fpm \
  php8.2-mysql \
  php8.2-curl \
  php8.2-gd \
  php8.2-intl \
  php8.2-mbstring \
  php8.2-soap \
  php8.2-xml \
  php8.2-zip \
  wget \
  curl \
  && ln -s /usr/sbin/php-fpm8.2 /usr/local/bin/php-fpm \

# Create WordPress directory
WORKDIR /var/www/html

# chown changes ownership -R recursivamente de mysql del grupo mysql para que pueda modificar /var/run/mysqld
RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chmod 755 /var/run/mysqld

EXPOSE 9000

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/
COPY tools/wordpress.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/wordpress.sh

ENTRYPOINT [ "/usr/local/bin/wordpress.sh" ]
```

**Configuration file**
```conf
[www]
user = www-data
group = www-data
listen = 9000
listen.owner = www-data
listen.group = www-data
pm = dynamic
pm.max_children = 5
pm.start_servers = 2
pm.min_spare_servers = 1
pm.max_spare_servers = 3
```

**Initialization script**
```sh
#!/bin/bash
set -e

WP_PATH="/var/www/html"

# Read password from secret file
if [ -n "$WORDPRESS_DB_PASSWORD_FILE" ] && [ -f "$WORDPRESS_DB_PASSWORD_FILE" ]; then
    WORDPRESS_DB_PASSWORD=$(cat "$WORDPRESS_DB_PASSWORD_FILE")
    export WORDPRESS_DB_PASSWORD
fi

echo "Setting up WordPress..."

# Download and configure WordPress if not present
if [ ! -f "$WP_PATH/wp-config.php" ]; then
    echo "Downloading WordPress..."
    wget -q https://wordpress.org/latest.tar.gz -O /tmp/wordpress.tar.gz
    tar -xzf /tmp/wordpress.tar.gz -C /tmp
    rm /tmp/wordpress.tar.gz

    # Copy only missing files (avoid overwriting existing content)
    cp -rn /tmp/wordpress/* "$WP_PATH" || true
    rm -rf /tmp/wordpress

    # Fetch security salts from WordPress API
    WP_SALTS=$(wget -qO- https://api.wordpress.org/secret-key/1.1/salt/)

    # Create wp-config.php
    cat > "$WP_PATH/wp-config.php" << EOF
<?php
define('DB_NAME', '${WORDPRESS_DB_NAME}');
define('DB_USER', '${WORDPRESS_DB_USER}');
define('DB_PASSWORD', '${WORDPRESS_DB_PASSWORD}');
define('DB_HOST', '${WORDPRESS_DB_HOST}');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

\$table_prefix = '${WORDPRESS_TABLE_PREFIX:-wp_}';

${WP_SALTS}

define('WP_DEBUG', false);

if ( !defined('ABSPATH') )
    define('ABSPATH', __DIR__ . '/');

require_once ABSPATH . 'wp-settings.php';
EOF

    # Set secure permissions
    find "$WP_PATH" -type d -exec chmod 750 {} \;
    find "$WP_PATH" -type f -exec chmod 640 {} \;
    chown -R www-data:www-data "$WP_PATH"

    echo "WordPress setup complete."
else
    echo "WordPress already initialized, skipping setup."
fi

echo "Starting PHP-FPM..."
exec php-fpm8.2 -F
```

## Docker-compose

```yaml
networks:
  inception-network:
    driver: bridge


services:
  mariadb:
    build: 
      context: requirements/mariadb
    image: mariadb:inception
    container_name: mariadb
    networks:
      - inception-network
    volumes:
      - mariadb_data:/var/lib/mysql
    environment:
      MYSQL_ROOT_PASSWORD_FILE: /run/secrets/db_root_password
      MYSQL_DATABASE: ${MYSQL_DATABASE}
      MYSQL_USER: ${MYSQL_USER}
      MYSQL_PASSWORD_FILE: /run/secrets/db_password
    secrets:
      - db_root_password
      - db_password
    restart: always

  wordpress:
    build:
      context: requirements/wordpress
    image: wordpress:inception
    container_name: wordpress
    depends_on:
      - mariadb
    networks:
      - inception-network
    volumes:
      - wordpress_data:/var/www/html
    environment:
      WORDPRESS_DB_HOST: mariadb
      WORDPRESS_DB_NAME: ${MYSQL_DATABASE}
      WORDPRESS_DB_USER: ${MYSQL_USER}
      WORDPRESS_DB_PASSWORD_FILE: /run/secrets/db_password
      WORDPRESS_TABLE_PREFIX: wp_
    secrets:
      - db_password
    restart: always

  nginx:
    build:
      context: requirements/nginx
    image: nginx:inception
    container_name: nginx
    depends_on:
      - wordpress
    networks:
      - inception-network
    volumes:
      - wordpress_data:/var/www/html
    environment:
      DOMAIN_NAME: ${DOMAIN_NAME}
    restart: always

volumes:
  mariadb_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/data/mariadb
  wordpress_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/data/wordpress

secrets:
  db_root_password:
    file: ../secrets/db_root_password.txt
  db_password:
    file: ../secrets/db_password.txt

```

## Environment variables and secrets

En el `.env`
```env
DOMAIN_NAME=xwu.42.fr
MYSQL_ROOT_PASSWORD=secure_root_password
MYSQL_DATABASE=wordpress_db
MYSQL_USER=wp_user
MYSQL_PASSWORD=secure_user_password

# WordPress settings
WORDPRESS_DB_NAME=wordpress_db
WORDPRESS_DB_USER=wp_user
WORDPRESS_DB_PASSWORD=secure_user_password
WORDPRESS_DB_HOST=mariadb
WORDPRESS_TABLE_PREFIX=wp_
```

En /secrets
```sh
echo "root" > secrets/db_root_password.txt
echo "pass" > secrets/db_password.txt

chmod 600 secrets/*
```

## Makefile

```Makefile
# Variables
COMPOSE_FILE = srcs/docker-compose.yml
DATA_DIR = /home/$(USER)/data

.PHONY: all build up down clean fclean re

all: build up

# Create data directories
$(DATA_DIR)/mariadb:
    mkdir -p $(DATA_DIR)/mariadb

$(DATA_DIR)/wordpress:
    mkdir -p $(DATA_DIR)/wordpress

# Build images
build: $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress
    docker compose -f $(COMPOSE_FILE) build

# Start services
up:
    docker compose -f $(COMPOSE_FILE) up -d

# Stop services
down:
    docker compose -f $(COMPOSE_FILE) down

# Clean containers and images
clean:
    docker compose -f $(COMPOSE_FILE) down
    docker system prune -af

# Full clean including volumes
fclean: clean
    docker volume prune -f
    sudo rm -rf $(DATA_DIR)

# Rebuild everything
re: fclean all
```


## Conceptos teóricos que aparecen

## Páginas de referencia
* https://docs.docker.com/get-started/docker-concepts/building-images/writing-a-dockerfile/
* https://dev.to/alejiri/docker-nginx-wordpress-mariadb-tutorial-inception42-1eok
* https://github.com/caroldaniel/42sp-cursus-inception/blob/main/guides/Mandatory-en.md#MariaDB 
* https://github.com/TFHD/Inception/tree/main