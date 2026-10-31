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

RUN apt update
RUN apt install -y nginx openssl
RUN mkdir -p /etc/nginx/ssl

EXPOSE 443

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf
COPY tools/entrypoint.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]

# Execute using the configuration file as a global directive y stay in the background
CMD ["nginx", "-g", "daemon off;"] 
```

**Initialization script**

Ahora, en `/nginx/tools` creamos el archivo `entrypoint.sh` para que genere el coso el certificado

```sh
#!/bin/bash

set -e

if [ ! -f /etc/nginx/ssl/nginx.crt ]; then
    echo "Nginx: Generating self-signed SSL certificate"

    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=ES/ST=Bizkaia/L=Urduliz/O=42/CN=$DOMAIN_NAME"

    chmod 600 /etc/nginx/ssl/nginx.key
    chmod 644 /etc/nginx/ssl/nginx.crt

    echo "Nginx: Certificate generated at /etc/nginx/ssl/"

else
    echo "Nginx: SSL certificate already exists"

fi

echo "Starting Nginx..."
exec "$@"
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

En `/etc/nginx/sites-available` nos podemos encontrar con un archivo `default` que tiene lo básico, lo usaremos de plantilla ([documentación](https://nginx.org/en/docs/http/configuring_https_servers.html) y [este también](https://nginx.org/en/docs/beginners_guide.html#:~:text=considered%20a%20comment.-,Serving%20Static%20Content,-An%20important%20web)):

```ini
user www-data;
events {
    worker_connections 1024;
}

http {
    server {
        listen 443 ssl;
        listen [::]:443 ssl; # IPv6
        server_name login.42.fr;

        ssl_certificate /etc/ssl/certs/nginx.crt;
        ssl_certificate_key /etc/ssl/private/nginx.key;
        ssl_protocols TLSv1.2 TLSv1.3;

        root /var/www/html; # raíz del repositorio de Wordpress, cuando alguien intente entrar a "tulogin.42.fr/patata", nginx buscaría en /var/www/html/patata del volumen (*)
        index index.php; # archivo que se abre por defecto cuando intentas acceder a "tulogin.42.fr"

        location / { # Nginx se queda primero con las locations con el prefijo más largo (por ejemplo, si fuera "tulogin.42.fr/patata/pata", coincide con /patata y /, pero /patata es más largo), así que este location es prácticamente siempre el último, el default case
            try_files $uri $uri/ /index.php?$args; (**) intenta mirar el archivo exacto ("/var/www/html/patata"), luego, como directorio, y al final, como query
        }

        location ~ \.php$ { # Cuando sale ~, le prosigue regex; En este caso, lo que sea que termine en ".php"
            include fastcgi_params; #incluimos las variables para comunicarse con php-fpm
            fastcgi_pass wordpress:9000; # Sets the address of a FastCGI server
            fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name; #Si he buscado tulogin.42.fr/patata, tenemos que document_root es "/var/www/html" y el otro es /patata, pues esta directiva o así define la variable SCRIPT_FILENAME como /var/www/html/patata
            fastcgi_param QUERY_STRING    $query_string; # Lo mismo para el query
        }

        location ~ /\.ht { # No access archivos ocultos like .htpasswd
            deny all;
        }
    }

    server {
        listen 80;
        listen [::]:80;

        server_name login.42.fr;

        location / {
            return 301 https://$host$request_uri;
        }
    }
}
``` 

*Notas*

Tristemente, no se puede expandir variables de entorno en la configuración de Nginx, (se puede, pero ese un poco tedioso), así que lo vamos a poner a pelo.

(*) **Volumen compartido**: So, en el docker compose hacemos que compartan un mismo volumen que convencionalmente los hemos montado en sitios con el mismo nombre ("/var/www/html"), so ambos pueden acceder

(* *) **URI** (Uniform Resource Identifier): Si cogemos un enlace cualquiera de internet (uno con más chicha), por ejemplo "https://example.org/test/test1?search=test-question#part2", podemos dividir sus partes:
* scheme (protocolo): https
* authority (dominio): example.org
* path: test/test1
* query: search=test-question
* fragment: part2

A esto lo llamamos URL (Uniform Resource Locator), que es un tipo específico de URI para páginas web, pues por ejemplo, la dirección de un correo electrónico "mailto:user@example.org" también es un URI, scheme: mailto y path: user@example.org

**Docker-compose**

```yaml
networks:
  inception-network:
    name: inception-network
    driver: bridge

services:
  mariadb:
    image: mariadb
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
    image: wordpress
    build:
      context: requirements/wordpress
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
    image: nginx
    build:
      context: requirements/nginx
    container_name: nginx
    depends_on:
      - wordpress
    networks:
      - inception-network
    volumes:
      - wordpress_data:/var/www/html
    env_file:
        - .env
    ports:
      - "443:443"
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

**Actualizar el .env**

Añadir `DOMAIN_NAME=tulogin.42.fr` al final.
```env
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_ROOT_PASSWORD_FILE=/run/secrets/db_root_password.txt
MYSQL_PASSWORD_FILE=/run/secrets/db_password.txt
MYSQL_HOST=mariadb
DOMAIN_NAME=login.42.fr
```