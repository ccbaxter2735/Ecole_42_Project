#!/bin/bash

echo "SHOW DATABASE... "

# Exécuter la commande dbshell et exécuter la requête SQL
echo "SELECT username, is_online, profile_image FROM game_user;" | python3 manage.py dbshell

