FROM debian:bookworm

RUN apt update && apt install -y \
    php8.2-fpm \
    php-mysql \
    curl \
    wget \
    unzip \
    mariadb-client

RUN mkdir -p /var/www/html
WORKDIR /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 9000

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/
COPY tools/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

RUN mkdir -p /var/www/html/wordpress/wp-content/themes
COPY conf/themes/* /var/www/html/wordpress/wp-content/themes
RUN chmod -R 755 /var/www/html/wordpress/wp-content
RUN chown -R www-data:www-data /var/www/html/wordpress/wp-content

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]
CMD ["php-fpm8.2", "-F"]