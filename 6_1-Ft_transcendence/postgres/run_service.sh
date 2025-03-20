#!/bin/bash

sudo -u postgres psql
sleep 2
CREATE DATABASE transdb;
CREATE USER terussar WITH PASSWORD 'pass';
GRANT ALL PRIVILEGES ON DATABASE transdb TO terussar;
