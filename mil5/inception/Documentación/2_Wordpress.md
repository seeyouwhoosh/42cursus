# Wordpress

Wordpress es un sistema escrito en PHP que se usa junto a MySQL o MariaDB para hacer cosas en la web, principalmente páginas web, newsletters, foros, LMS, tiendas y así.

Los requisitos para correr Wordpress:
* PHP 8.3 or greater
* MariaDB 10.6 or greater OR MySQL 8.0 or greater
* Nginx or Apache with mod_rewrite module
* HTTPS support

Siguiendo el [tutorial Wordpress](https://codex.wordpress.org/es:Instalando_WordPress)

**Dockerfile**
```Dockerfile
FROM debian:bookworm

RUN apt update && apt install -y \
    php-fpm \ 
    php-mysql \
    curl \
    wget \
    unzip \

RUN ln -s /usr/sbin/php-fpm8.4 /usr/local/bin/php-fpm

# Create WordPress directory
RUN mkdir -p /var/www/html
WORKDIR /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 9000

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/
COPY tools/wordpress.sh /usr/local/bin/


RUN chmod +x /usr/local/bin/wordpress.sh

ENTRYPOINT [ "/usr/local/bin/wordpress.sh" ]

CMD ["php-fpm8.4", "-F"]
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

cd /var/www/html

# Secretos
if [ -f "$MYSQL_PASSWORD_FILE" ]; then
    MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
fi

# Descargar WordPress tal cuál te dice su página: https://developer.wordpress.org/advanced-administration/before-install/howto-install/
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

    chown -R www-data:www-data /var/www/html
fi

# Esperar a MariaDB
until mysqladmin ping -hmariadb --silent; do
    echo "Waiting for MariaDB..."
    sleep 2
done

echo "WordPress: Starting PHP-FPM..."
exec "$@"
```

**Actualizar el docker-compose**
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

**Actualizar el .env**

```env
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_ROOT_PASSWORD_FILE=/run/secrets/db_root_password.txt
MYSQL_PASSWORD_FILE=/run/secrets/db_password.txt
MYSQL_HOST=mariadb
```
