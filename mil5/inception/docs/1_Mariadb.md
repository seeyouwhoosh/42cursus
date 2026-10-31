# MariaDB

MariaDB es una herramienta para gestionar bases de datos relacionales (lo que sea que sea eso), en fin, se usa para estructurar información. Es un fork de MySQL, sigue siendo muy compatible.

El Dockerfile prepara el contenedor, la mini máquina virtual para "acoger al programa", esto quiere decir que no comparten archivos (esto me ha dado algún que otro problema). 


### Cómo funciona más o menos esto
Sacado de la documentación de MariaDB: [Installing and Using MariaDB via Docker](https://mariadb.com/docs/server/server-management/automated-mariadb-deployment-and-administration/docker-and-mariadb/installing-and-using-mariadb-via-docker)

Si pruebas a hacer el siguiente comando, se te setupea todo, con todas las dependencias y todo:

```sh
docker pull mariadb:10.6
docker run --name mariadbtest -e MYSQL_ROOT_PASSWORD=mypass -p 3306:3306 -d mariadb:10.6
```

Haz `docker ps` para saber si está corriendo. Luego, puedes intentar entrar a la terminal del contenedor (que en este caso será la misma terminal que Debian porque nuestra imagen base es Debian) escribiendo `docker exec -it mariadbtest bash` 

Ahora, para conectarte directamente a mariadb del contenedor estando fuera de este, necesitas saber qué dirección IP tiene, porque recuerda que los contenedores están en una red bridge, se conectan entre sí y con el host, pero no es la red localhost.

De hecho, si intentas conectarte te dará un error `ERROR 2002 (HY000): Can't connect to local server through socket '/run/mysqld/mysqld.sock'` porque está intentando buscar el socket file local, pero el mariadb corre en un contenedor...

En fin, corre esto para hacer una especie de grep y encontrar en qué red está cuando esté corriendo
```sh
docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' mariadbtest
```

Ó puedes buscarlo manualmente con
```sh
docker network inspect inception-network
```

Y luego haz `mysql -h 172.17.0.2 -u root -p --skip-ssl` (la contraseña establecida en el ejemplo es "mypass"). ¿Funciona? Yay.

## El setup en sí

**Configuration file**
Tras ejecutar la imagen prueba del inicio, he copiado directamente el archivo /etc/mysql/mariadb.conf.d/50-server.cnf, que solo tenemos que cambiar para que escuche de más direcciones

```ini
[mysqld]
# [...] He borrado lo que era demasiado enveresado, porque eran para otros programas del mariadb y a nosotros prácticamente solo nos interesa las opciones de servidor. 
user                    = mysql
pid-file                = /run/mysqld/mysqld.pid
socket                  = /run/mysqld/mysqld.sock # permite a una aplicación conectarse a una base de datos para enviar consultas y recibir resultados
port                    = 3306
basedir                 = /usr
datadir                 = /var/lib/mysql # directorio de all database files
tmpdir                  = /tmp
lc-messages-dir         = /usr/share/mysql
#Instead of skip-networking the default is now to listen only on
#localhost which is more compatible and is not less secure.
bind-address            = 0.0.0.0
query_cache_size        = 16M
log_error = /var/log/mysql/error.log
expire_logs_days        = 10
character-set-server  = utf8mb4
collation-server      = utf8mb4_general_ci
```

**Dockerfile**

Siendo honesta, no tengo ni la menor idea de dónde saca la gente este Dockerfile (que ya ni sé de quién es, porque lo he ido reemplazando). Pero bueno, del archivo de configuración se puede sacar algunas conclusiones.

(Por cierto, técnicamente no está completo, porque luego vamos a importar la base de datos configurada)

```Dockerfile
# Imagen base que usaremos para construir la imagen de la aplicación (penúltima versión: 12, bookworm, porque la última estable es trixie, y quien te diga que no, que me pelee). Más ejemplos de bases: python
FROM debian:bookworm

RUN apt update
RUN apt install -y mariadb-server mariadb-client

# Creamos los directorios necesarios (los que se piden arriba, vamos)
# chown "changes ownership" -R "recursivamente" a mysql del grupo mysql (mysql es el usuario que pusimos en el conf) para que pueda modificar las dos carpetas
# Que todos los demás no tengan permisos de escritura
RUN mkdir -p /var/run/mysqld /var/lib/mysql /var/log/mysql \
    && chown -R mysql:mysql /var/run/mysqld /var/lib/mysql /var/log/mysql \
    && chmod 755 /var/run/mysqld

# Indica qué puerto se expone la imagen
EXPOSE 3306

# Copiamos el el archivo de configuración y el script de inicialización
# Si te preguntas porqué se copia en un archivo 99-custom.cnf, es porque mariadb lee los archivos de configuración en orden descendiente alfanuméricamente, so, para que este sea de los últimos en ejecutor, ponemos 99
COPY conf/custom.conf /etc/mysql/mariadb.conf.d/99-custom.cnf
COPY tools/entrypoint.sh /usr/local/bin/

# ENTRYPOINT y CMD definen los comandos que se ejecutan cuando corre un contenedor, esta es la sintaxis preferente y also, la que más sentido tiene. En caso de que haya ENTRYPOINT y CMD definidos, siempre se ejecuta el ENTRYPOINT primero con el CMD apendizado como argumentos (que es realmente el comando para inicializar la aplicación, ejecutado en el .sh)
RUN chmod +x /usr/local/bin/entrypoint.sh
ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]
CMD ["mysqld", "--user=mysql", "--datadir=/var/lib/mysql"]
```

**Initialization script**

Esta es la parte en la que realmente se setupea y se ejecuta el programa; también es la que más probablemente dé problemas creo yo (porque well, si ha corrido el contenedor, supongo que ha ido todo bien). 

La base lo he copiado de otras personas (cambiando cosas aquí y allí), pero he encontrado que la [imagen docker oficial de mariadb](https://github.com/MariaDB/mariadb-docker/blob/master/docker-entrypoint.sh) hace prácticamente lo mismo pero más seguro

```sh
#!/bin/bash

# En la subject dice que no password en el git excepto en secrets (*)
MYSQL_PASSWORD=$(cat "$MYSQL_PASSWORD_FILE")
MYSQL_ROOT_PASSWORD=$(cat "$MYSQL_ROOT_PASSWORD_FILE")

# Para si da error, que pare
set -e

# Initialize MySQL data directory if it doesn't exist
if [ ! -d "/var/lib/mysql/mysql" ]; then
  echo "MariaDB: Initializing database..."
  mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null
fi

if [ ! -d "/var/lib/mysql/wordpress" ]; then
# Con el & significa empezarlo en segundo plano; y sin aceptar conexiones red todavía, porque solo lo estamos setupeando
  echo "MariaDB: Starting temporary MariaDB..."
  mysqld_safe --datadir=/var/lib/mysql --skip-networking &

  # mariadb-admin ping mira si está vivo el servidor
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
fi

echo "MariaDB: Starting MariaDB..."
exec "$@"
```

_Notas_
(*) Lo de las contraseñas: es más cosa del docker-compose. Pero básicamente, el docker-compose le inyecta los archivos correspondientes al contenedor, lo copia a la carpeta /run/secrets. Por otro lado, paso al contenedor variables de entorno que le dicen dónde está (SMYSQL_ROOT_PASSWORD=tal)

* Las variables se expanden a pesar de tener variables simples, algo del sql. Eso sí, he tenido que poner llaves porque por alguna razón no se lee bien al ejecutar.

* `mysql_install_db`: initializes the MariaDB data directory and creates the system tables in the mysql database.  Equivalente a [docker_init_database_dir()](https://github.com/MariaDB/mariadb-docker/blob/master/docker-entrypoint.sh#L232)
  *  `--user=mysql `: que los archivos pertenezcan al usuario este (kinda como lo hemos puesto en config)
  *  `--datadir=/var/lib/mysql`: base de datos
  * `> /dev/null` kinda like shut up, talk to the wall

* `mysql_safe`: intenta iniciar el ejecutable llamado "mysqld" (servidor). Es más seguro que hacer directamente `mysqld`, porque cuando ocurre un error, crea un error log y lo reintenta. Equivalente a [docker_temp_server_start()](https://github.com/MariaDB/mariadb-docker/blob/master/docker-entrypoint.sh#L121)
  * `--datadir` Path to data directory

* Editar permisos de usuarios de mariadb
Más información en [los docs](https://mariadb.com/docs/server/reference/sql-statements/account-management-sql-statements)

```sh
# Modifica la contraseña actual del usuario root conectado mediante el socket local
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

# grants all available privileges on the given priviledge level y con el GRANT OPTION, give users the ability to grant privileges to other users at the given privilege level
GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' WITH GRANT OPTION;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';

# Reload
FLUSH PRIVILEGES;
```

**Para comprobar que funciona individualmente**

[Página útil para ver los usuarios, los hosts y cosas así](https://www.cyberciti.biz/faq/how-to-show-list-users-in-a-mysql-mariadb-database/)

```sh
docker build -t mariadb-test .
docker run -it \
  -v ../../secrets/db_root_password.txt:/run/secrets/db_root_password.txt \
  -v ../../secrets/db_password.txt:/run/secrets/db_password.txt \
  -p 3306:3306 \
  -e MYSQL_ROOT_PASSWORD_FILE=/run/secrets/db_root_password.txt \
  -e MYSQL_DATABASE=wordpress \
  -e MYSQL_USER=wpuser \
  -e MYSQL_PASSWORD_FILE=/run/secrets/db_password.txt \
  mariadb-test
```

Si funciona, pone "Listening for connections" o algo así

Si abres otra terminal y pones
```sh
mariadb -h localhost -P 3306 -u wpuser -p
```
Tras poner la contraseña (`wppass`), debería no pasar nada.

## Cambios en los archivos globales

Las variables de entorno las colocamos en `.env`

```env
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_ROOT_PASSWORD_FILE=/run/secrets/db_root_password
MYSQL_PASSWORD_FILE=/run/secrets/db_password
```

Y las contraseñas en los respectivos archivos en /secrets
```sh
echo "wppass" > ../secrets/db_root_password.txt
echo "rootpass" > ../secrets/db_password.txt

chmod 600 ../secrets/*
```

**Actualizar el docker-compose**

```yaml
networks:
  inception-network:
    name: inception-network
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

volumes:
  mariadb_data:
    driver: local #almacenamiento local
    driver_opts:
      type: none
      o: bind # share a directory from the host's filesystem into the container
      device: /home/${USER}/data/mariadb # usa este sitio para guardar los datos

secrets: #esto luego se copia a la carpeta /run/secrets como db_root_password
  db_root_password:
    file: ../secrets/db_root_password.txt
  db_password:
    file: ../secrets/db_password.txt
```

Una vez hecho esto, debería funcionar con el comando `docker compose up`.

## Cómo loggearse a la database

Para empezar, si has estado atento a la sección [segunda o así](###-Cómo-funciona-más-o-menos-esto) ya sabes dos formas de entrar a la database, elige la que funcione (el primero es la forma segura):

* **Entrando al contenedor**: 
1. Escribe `docker -it mariadb bash` en la terminal
2. Dentro del contenedor, escribe `mariadb -u root -h localhost -d wordpress -p`

* **Sin entrar al contenedor**: 
1. Instala mariadb si aún no lo has hecho: `sudo apt install mariadb-server mariadb-client`
2. Saca la IP interna del contenedor haciendo `docker inspect <container id> | grep "IPAddress"`
3. Conéctate haciendo `mariadb -u wpuser -h <IPadress> -d wordpress -p`

Estando dentro, si en mariadb no está indexado "wordpress" como base de datos, haz `use wordpress` (realmente debería estar indexado, si no lo está, entra en pánico. Pongo el comando por si pasa algo). Luego, para mostrar las cosas (entre corchetes lo opcional):

```mariadb
show [full] tables
[from database_name];
```

Y para ver el contenido (es probable que no haya nada ahora, si no has configurado el wordpress):

```mariadb
select select_list
from table_name;
```
