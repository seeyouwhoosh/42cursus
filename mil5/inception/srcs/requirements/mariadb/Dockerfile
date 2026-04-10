FROM debian:bookworm

RUN apt update && apt install -y mariadb-server mariadb-client

RUN mkdir -p /var/run/mysqld /var/lib/mysql \
    && chown -R mysql:mysql /var/run/mysqld /var/lib/mysql  \
    && chmod 755 /var/run/mysqld

EXPOSE 3306

COPY conf/custom.conf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf
COPY tools/entrypoint.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/entrypoint.sh
ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]
CMD ["mysqld", "--user=mysql", "--datadir=/var/lib/mysql"]
