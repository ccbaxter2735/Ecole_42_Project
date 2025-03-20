#!/bin/bash

echo "initialization of GAME migrations... "

python3 manage.py makemigrations

python3 manage.py migrate

# python3 manage.py createsuperuser --username=thomas --email=admin@example.com --noinput

python3 manage.py collectstatic --noinput

python3 manage.py runserver 0.0.0.0:8000

echo "end migrations"
