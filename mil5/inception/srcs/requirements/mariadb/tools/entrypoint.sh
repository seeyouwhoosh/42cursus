#!/bin/bash

MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
MYSQL_ROOT_PASSWORD=$(cat "$MYSQL_ROOT_PASSWORD_FILE")

set -e



if [ ! -d "/var/lib/mysql/mysql" ]; then
  echo "MariaDB: Initializing database..."


    mariadb-install-db --user=mysql --datadir=/var/lib/mysql
fi

echo "MariaDB: Starting temporary MariaDB..."
mysqld_safe  -uroot -p"$MYSQL_ROOT_PASSWORD" --socket="/var/run/mysqld/mysqld.sock" --datadir='/var/lib/mysql' --skip-networking &

until mysqladmin ping -uroot -p"$MYSQL_ROOT_PASSWORD" --socket="/var/run/mysqld/mysqld.sock"; do
    echo "MariaDB: Waiting for MariaDB to start..."
    sleep 1
done

DB_EXISTS=$(mysql -uroot -p"$MYSQL_ROOT_PASSWORD" -e "SHOW DATABASES LIKE '$MYSQL_DATABASE';" | grep -q "$MYSQL_DATABASE")

if [ "$DB_EXISTS" -eq 1 ]; then
  mariadb -uroot -p"$MYSQL_ROOT_PASSWORD" << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF
  echo "MariaDB: Stopping temporary MariaDB..."
  mysqladmin -uroot -p"$MYSQL_ROOT_PASSWORD" --socket="/var/run/mysqld/mysqld.sock" shutdown
fi

echo "MariaDB: Starting MariaDB..."
exec "$@"