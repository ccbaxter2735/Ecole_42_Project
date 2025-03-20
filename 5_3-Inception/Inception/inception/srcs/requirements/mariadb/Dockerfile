#
# MARIADB - Inception project 42
#
FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install mariadb-server mariadb-client procps -y


RUN mkdir -p /var/run/mysql && chown mysql:mysql /var/run/mysql && chmod 755 /var/run/mysql
RUN mkdir -p /var/lib/mysql && chown mysql:mysql /var/lib/mysql && chmod 755 /var/lib/mysql

COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY	./tools/mariadb.sh /mariadb.sh

RUN	chmod 755 /mariadb.sh

ENTRYPOINT	["./mariadb.sh"]

EXPOSE	3306

CMD		["mysqld_safe"]
