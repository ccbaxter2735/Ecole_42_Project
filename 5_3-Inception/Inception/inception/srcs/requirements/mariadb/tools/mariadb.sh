#!/bin/bash

#demarrage mysql
service mariadb start;
sleep 5;
#service mariadb status;
#creation de la base
mariadb -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
#creation de l utilisateur 
mariadb -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';"
#donne droits utilisateur
mariadb -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
#def mot de passe pour modif droits root
mariadb -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
#rafraichir pour prise en compte des chgts
mariadb -e "FLUSH PRIVILEGES;"
#redemarage mysql
mysqladmin -u root -p$SQL_ROOT_PASSWORD shutdown

exec "$@"
