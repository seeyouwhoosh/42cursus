# Wordpress

Wordpress es un sistema escrito en PHP que se usa junto a MySQL o MariaDB para hacer cosas en la web, principalmente páginas web, newsletters, foros, LMS, tiendas y así.

Los requisitos para correr Wordpress:
* PHP 8.3 or greater
* MariaDB 10.6 or greater OR MySQL 8.0 or greater
* Nginx or Apache with mod_rewrite module
* HTTPS support

## El setup en sí
**Initialization script**

Siguiendo el [tutorial Wordpress](https://codex.wordpress.org/es:Instalando_WordPress) o también como te dice su página: https://developer.wordpress.org/advanced-administration/before-install/howto-install/

Trabajaremos en el directorio `/var/www/html` del contenedor, que es el directorio predeterminado para aloar archivos de sitios webs gestionados por Nginx.

La forma de instalarse wordpress es:
1. Descargarse el zip de la página web
2. Descomprimir el zip 
3. Ir reemplazando los campos en los que diga "no sé _here" con los datos del .env

```sh
#!/bin/bash
set -e

cd /var/www/html

if [ -f "$MYSQL_PASSWORD_FILE" ]; then
  MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
fi

if [ ! -f wp-config.php ]; then
    echo "WordPress: Downloading..."

    wget https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress latest.tar.gz

    echo "WordPress: Configuring..."

    cp wp-config-sample.php wp-config.php

    sed -i "s/database_name_here/${MYSQL_DATABASE}/" wp-config.php
    sed -i "s/username_here/${MYSQL_USER}/" wp-config.php
    sed -i "s/password_here/${MYSQL_PASSWORD}/" wp-config.php
    sed -i "s/localhost/${MYSQL_HOST}/" wp-config.php

# www-data es el usuario predeterminado que ejecuta los webservers
    chown -R www-data:www-data /var/www/html
fi

until mariadb-admin ping -hmariadb --silent; do
    echo "WordPress: Waiting for MariaDB..."
    sleep 2
done

echo "WordPress: Starting PHP-FPM..."
exec "$@"
```

Con esto tenemos la base de datos preparada (Mariadb) y Wordpress casi setupeado. Nos falta por setupear un modo de acceso a la página web, que se hará mediante php-fpm y Nginx, ¡disponible en la última parte de la trilogía! Stay tuned. Por ahora todavía tenemos configurar el resto de cosas el dockerfile y tal.

**Dockerfile**

Prácticamente es como la del Mariadb.

```Dockerfile
FROM debian:bookworm

RUN apt update && apt install -y \
    php-fpm \ 
    php-mysql \
    curl \
    wget \
    unzip \

RUN ln -s /usr/sbin/php-fpm8.4 /usr/local/bin/php-fpm

RUN mkdir -p /var/www/html
WORKDIR /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 9000

COPY conf/www.conf /etc/php/8.4/fpm/pool.d/
COPY tools/entrypoint.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]

CMD ["php-fpm", "-F"]
```

**Configuration file**

El archivo de configuración que vamos a manejar aquí es actually del php-fpm, el **FastCGI Process Manager**.
* **FastCGI**: Es un protocolo que define cómo el servidor web (Nginx) se comunica con el programa CGI, pero en vez de crear procesos nuevos para manejar cada petición, maneja todas las peticiones con un único proceso.
* **CGI**: Common Gateway Interface. Es un método para interconectar aplicaciones externas con servidores web. A estas aplicaciones las llamamos programas CGI.

En fin, que PhP implementó su propio FastCGI, especializado para manejar los procesos php y los requests php de lo que reciba de Nginx.

Voy a coger el predeterminado, aunque como el archivo tiene chorrocientos comentarios, voy a recomentarlo (almohadillas)

Pool en pfp-fpm es al parecer, un grupo de procesos que corren para una única aplicación o servicio, y en este caso, solo estamos configurando el pool para `[www]`, que es el default

```ini
[www]
# Usuario y grupo con el que se van a ejecutar los procesos
user = www-data
group = www-data

; The address on which to accept FastCGI requests.
; Valid syntaxes are:
;   'ip.add.re.ss:port'    - to listen on a TCP socket to a specific IPv4 address on
;                            a specific port; [...]
;   'port'                 - to listen on a TCP socket to all addresses
;                            (IPv6 and IPv4-mapped) on a specific port;
;   '/path/to/unix/socket' - to listen on a unix socket.
; Note: This value is mandatory.

#Este es literalmente el único cambio que hago (valor original "/run/php/php8.4-fpm.sock"), porque quiero escuchar a Nginx desde el puerto abierto y realmente, la única vía razonable (Nginx no puede acceder a los sockets porque están en contenedores distintos y tampoco tenemos una dirección IP fija para dar)
listen = 9000

; Set permissions for unix socket, if one is used. In Linux, read/write
; permissions must be set in order to allow connections from a web server. Many
; BSD-derived systems allow connections regardless of permissions. The owner
; and group can be specified either by name or by their numeric IDs.
; Default Values: Owner is set to the master process running user. If the group
;                 is not set, the owner's group is used. Mode is set to 0660.
listen.owner = www-data
listen.group = www-data
;listen.mode = 0660

; Choose how the process manager will control the number of child processes.
; Possible Values:
;   static  - a fixed number (pm.max_children) of child processes;
;   dynamic - the number of child processes are set dynamically based on the
;             following directives. With this process management, there will be
;             always at least 1 children.
;             pm.max_children      - the maximum number of children that can
;                                    be alive at the same time.
;             pm.start_servers     - the number of children created on startup.
;             pm.min_spare_servers - the minimum number of children in 'idle'
;                                    state (waiting to process). If the number
;                                    of 'idle' processes is less than this
;                                    number then some children will be created.
;             pm.max_spare_servers - the maximum number of children in 'idle'
;                                    state (waiting to process). If the number
;                                    of 'idle' processes is greater than this
;                                    number then some children will be killed.
;             pm.max_spawn_rate    - the maximum number of rate to spawn child
;                                    processes at once.
;  ondemand - no children are created at startup. Children will be forked when
;             new requests will connect. The following parameter are used:
;             pm.max_children           - the maximum number of children that
;                                         can be alive at the same time.
;             pm.process_idle_timeout   - The number of seconds after which
;                                         an idle process will be killed.
; Note: This value is mandatory.
pm = dynamic

; The number of child processes to be created when pm is set to 'static' and the
; maximum number of child processes when pm is set to 'dynamic' or 'ondemand'.
; This value sets the limit on the number of simultaneous requests that will be
; served. Equivalent to the ApacheMaxClients directive with mpm_prefork.
; Equivalent to the PHP_FCGI_CHILDREN environment variable in the original PHP
; CGI. The below defaults are based on a server without much resources. Don't
; forget to tweak pm.* to fit your needs.
; Note: Used when pm is set to 'static', 'dynamic' or 'ondemand'
; Note: This value is mandatory.
pm.max_children = 5

; The number of child processes created on startup.
; Note: Used only when pm is set to 'dynamic'
; Default Value: (min_spare_servers + max_spare_servers) / 2
pm.start_servers = 2

; The desired minimum number of idle server processes.
; Note: Used only when pm is set to 'dynamic'
; Note: Mandatory when pm is set to 'dynamic'
pm.min_spare_servers = 1

; The desired maximum number of idle server processes.
; Note: Used only when pm is set to 'dynamic'
; Note: Mandatory when pm is set to 'dynamic'
pm.max_spare_servers = 3
```

## Cambios globales

**Actualizar el docker-compose**

Prácticamente es como la del Mariadb.

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

Añadir `MYSQL_HOST=mariadb` al final, ya que lo usamos en el script...

```env
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_ROOT_PASSWORD_FILE=/run/secrets/db_root_password.txt
MYSQL_PASSWORD_FILE=/run/secrets/db_password.txt
MYSQL_HOST=mariadb
```
