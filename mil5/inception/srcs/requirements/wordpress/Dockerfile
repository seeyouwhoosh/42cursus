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
COPY tools/wordpress.sh /usr/local/bin/


RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]

CMD ["php-fpm", "-F"]