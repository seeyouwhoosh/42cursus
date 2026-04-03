# Nginx
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
FROM debian:bookworm

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

## Docker-compose

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
      - mariadb_data:/var/lib/mysql #montada allí
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
    driver: local #almacenamiento local
    driver_opts:
      type: none
      o: bind # share a directory from the host's filesystem into the container
      device: /home/${USER}/data/mariadb # usa este sitio para guardar los datos
  wordpress_data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/data/wordpress

secrets: #esto luego se copia a la carpeta /run/secrets
  db_root_password:
    file: ../secrets/db_root_password.txt
  db_password:
    file: ../secrets/db_password.txt

```