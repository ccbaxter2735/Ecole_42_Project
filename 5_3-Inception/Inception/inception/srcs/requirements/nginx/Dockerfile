#
# NGINX - Inception project 42
#
FROM debian:bullseye

RUN	apt update -y \
	&& apt upgrade -y \
	&& apt install nginx -y \
	&& apt-get install openssl -y 
	
RUN	mkdir -p /etc/nginx/ssl
	
RUN	openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=terussar.42.fr/UID=terussar"

RUN	mkdir -p /var/run/nginx

EXPOSE	443

COPY	conf/nginx.conf /etc/nginx/nginx.conf

RUN	chmod 755 /var/www/html

RUN	chown -R www-data:www-data /var/www/html

CMD	[ "nginx", "-g", "daemon off;"]

