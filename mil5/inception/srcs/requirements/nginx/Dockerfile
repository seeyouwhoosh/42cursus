FROM debian:bookworm

RUN apt update && apt install -y nginx openssl
RUN mkdir -p /etc/nginx/ssl

EXPOSE 443

COPY conf/nginx.conf /etc/nginx/conf.d/default.conf
COPY tools/entrypoint.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]
CMD ["nginx", "-g", "daemon off;"]