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

    chown -R www-data:www-data /var/www/html
fi

until mariadb-admin ping -hmariadb --silent; do
    echo "WordPress: Waiting for MariaDB..."
    sleep 2
done

echo "WordPress: Starting PHP-FPM..."
exec "$@"