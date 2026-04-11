#!/bin/bash

MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
MYSQL_ROOT_PASSWORD=$(cat "$MYSQL_ROOT_PASSWORD_FILE")

set -e

if [ ! -d "/var/lib/mysql/mysql" ]; then
  echo "MariaDB: Initializing database..."
  mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null
fi

echo "MariaDB: Starting temporary MariaDB..."
mysqld_safe --datadir=/var/lib/mysql --skip-networking &

until mariadb-admin ping --silent; do
sleep 1
done

mariadb -u root -h localhost << EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

echo "MariaDB: Stopping temporary MariaDB..."
mysqladmin -uroot -p${MYSQL_ROOT_PASSWORD} shutdown

echo "MariaDB: Starting MariaDB..."
exec "$@"
