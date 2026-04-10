# Inception

> [😡] Antes de que intentes copiar el comando de abajo e ir copiando y pegando los contenidos de los archivos, hay una forma mucho más rápida de mover toda la carpeta del ordenador a la máquina virtual. Solo necesitas que se pueda acceder a la máquina virtual mediante ssh. Lo pongo [abajo](##-Yo-poner-archivos), porque... es el orden cronológico de hacer las cosas

## Preparar los directorios

```ssh
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
&& touch inception/Makefile inception/secrets/{credentials.txt,db_password.txt,db_root_password.txt} inception/srcs/{docker-compose.yml,.env} inception/srcs/requirements/{mariadb,nginx,wordpress}/{Dockerfile,.dockerignore}
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

sudo groupadd docker
sudo usermod -aG docker $USER
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

La plantilla del docker-compose de este proyecto (no todos los campos son necesarios y he puesto algunos ejemplos y formatos como comentarios):

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
      - mariadb_data:/var/lib/mysql #nombre:dónde
    env_file: #alternativa para usar env (${VAR}): "environment:"
      .env
    secrets:
      #-db_passwords
    restart: on-failure #restartea si el contenedor ha salido con error

volumes: 
  mariadb_data: #nombre del volumen
    driver: # tipo de volumen
    driver_opts: # opciones avanzadas de lo de arriba
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

Y como los contenedores van a estar en esa network, lo declaramos en nuestro docker-compose.yml (no hace falta que lo crees manualmente, el docker compose ya lo crea):

```yml
networks:
  inception-network:
    driver: bridge
```

## Setup de servicios

Bien, ya podemos empezar a montar nuestra página web desde casi cero :D
El orden preferente es
1. MariaDB
2. Wordpress
3. Nginx

## Cómo queda el docker compose final

```yaml
networks:
  inception-network:
    driver: bridge

services:
  mariadb:
    build: 
      context: requirements/mariadb
    container_name: mariadb
    networks:
      - inception-network
    volumes:
      - mariadb_data:/var/lib/mysql
    env_file:
      - .env
    secrets:
      - db_root_password
      - db_password
    restart: always
  wordpress:
    build: requirements/wordpress
    container_name: wordpress
    depends_on:
      - mariadb
    networks:
      - inception-network
    volumes:
      - wordpress_data:/var/www/html
    env_file:
        - .env
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

### Bind mounts y named volumes

In general, --mount is preferred. The main difference is that the --mount flag is more explicit and supports all the available options.

If you use --volume to bind-mount a file or directory that does not yet exist on the Docker host, Docker automatically creates the directory on the host for you. It's always created as a directory.

--mount does not automatically create a directory if the specified mount path does not exist on the host.

En la práctica, en el docker-compose, que hagas esto:
```yaml
services:
  mariadb:
    volumes:
      - db_data:/var/lib/mysql

  wordpress:
    volumes:
      - wp_data:/var/www/html

volumes:
  db_data:
  wp_data:
```
en vez de esto (se supone que los *_data son carpetas en el host):
```yaml
services:
  mariadb:
    volumes:
      - ./mariadb_data:/var/lib/mysql

  wordpress:
    volumes:
      - ./wordpress_data:/var/www/html
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
    sudo chown -R $USER:$USER /home/$USER/data/mariadb
    chmod 755 /home/$USER/data/mariadb

$(DATA_DIR)/wordpress:
    mkdir -p $(DATA_DIR)/wordpress
    sudo chown -R $USER:$USER /home/$USER/data/wordpress
    chmod 755 /home/$USER/data/wordpress

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
    docker system prune -af # limpia recursos que no se están usando, -a incluyendo imágenes y -f forced

# Full clean including volumes
fclean: clean
    docker volume prune -f
    sudo rm -rf $(DATA_DIR)

# Rebuild everything
re: fclean all
```

## Yo poner archivos (final)
Vamos a usar FTP, ~~free to play~~, File Transfer Protocol, pero actually SFTP, que es más secure y más conveniente porque corre como un subsistema del SSH y así no tenemos que abrir más puertos, basta usar el que hemos abierto para el SSH.

Entonces, en una terminal en el ordenador (no la máquina virtual), preferiblemente en el directorio en el que tengas todos los archivos, haces:

```sh
ftp localhost -P 4241 # Estoy suponiendo que tus nombres de usuario en ambos sitios son iguales, si no, haz "username@localhost"
mkdir inception
put -r inception
```

**Más comandos relevantes por si necesitaras ajustar algo**
Comandos básicos como `cd`, `ls`, `mkdir` son para la máquina remota, mientras que si le pones una 'l' delante (`lcd`, `lls`...) es para tu maquina local, tiene sentido, ¿no?
* **`bye`**: to exit the FTP environment (same as quit)
* **`delete`**: to delete (remove) a file in the current remote directory (same as rm in UNIX)
* **`get`**: to copy one file from the remote machine to the local machine

## Páginas de referencia
* https://docs.docker.com/get-started/docker-concepts/building-images/writing-a-dockerfile/
* https://dev.to/alejiri/docker-nginx-wordpress-mariadb-tutorial-inception42-1eok
* https://github.com/caroldaniel/42sp-cursus-inception/blob/main/guides/Mandatory-en.md#MariaDB 
* https://github.com/TFHD/Inception/tree/main
* https://github.com/gemartin99/Inception/blob/main/inception/srcs/requirements/mariadb/conf/mariadb.conf