#!/bin/bash
sleep 5

mkdir -p /run/php

# Utiliser wp-cli pour configurer WordPress
cd /var/www/wordpress
# wp theme install astra.4.8.2 --activate
wp core download  --allow-root

wp core config --dbname=$SQL_DATABASE --dbuser=$SQL_USER --dbpass=$SQL_PASSWORD --dbhost=mariadb  --allow-root --skip-check

wp core install --url=$DOMAIN_NAME --title="Inception site" --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --path=/var/www/wordpress --allow-root
wp user create --allow-root $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=author --path=/var/www/wordpress
chown -R www-data:www-data /var/www/wordpress
chmod -R 755 /var/www/wordpress

exec "$@"
