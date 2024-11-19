#
# WORDPRESS - Inception project 42
#
FROM        debian:bullseye
RUN         apt update
RUN         apt install -y wget\
            php7.4\
            php-fpm\
            php-mysql\
			unzip\
            mariadb-client
RUN         wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN         chmod +x wp-cli.phar
RUN         mv wp-cli.phar /usr/local/bin/wp
RUN         echo "listen=9000" >> /etc/php/7.4/fpm/pool.d/www.conf 
COPY	    ./conf/config_wp.sh /config_wp.sh
# Créer le répertoire des thèmes si nécessaire
# RUN         mkdir -p /var/www/html/wp-content/themes
# RUN         chown -R www-data:www-data /var/www/html/wp-content/themes

# Téléchargement et installation du thème Astra
# COPY		themes/astra.4.8.2.zip /tmp/astra.4.8.2.zip
# RUN         unzip /tmp/astra.4.8.2.zip -d /var/www/html/wp-content/themes/ && \
#             rm /tmp/astra.4.8.2.zip
RUN         chmod 755 /config_wp.sh

ENTRYPOINT  ["./config_wp.sh"]

EXPOSE      9000

CMD ["php-fpm7.4", "-F"]
