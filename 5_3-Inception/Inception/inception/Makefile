HOST_USER       = terussar
PROJECT_NAME    = inception
COMPOSE_PATH	= ./srcs/docker-compose.yml

VOLUMES         = $(shell docker volume ls -q)

all: compose

compose: 
	mkdir -p /home/$(HOST_USER)/data/wordpress
	mkdir -p /home/$(HOST_USER)/data/mariadb
	docker compose -p $(PROJECT_NAME) -f $(COMPOSE_PATH) up --build -d 

start:
	docker compose -p $(PROJECT_NAME) -f $(COMPOSE_PATH) start

stop:
	docker compose -p $(PROJECT_NAME) -f $(COMPOSE_PATH) stop

down:
	docker compose -p $(PROJECT_NAME) -f $(COMPOSE_PATH) down

ps:
	docker compose -p $(PROJECT_NAME) -f $(COMPOSE_PATH) ps

check:
	docker ps
	docker images
	docker volume ls
	docker network ls

fclean: clean
	-docker system prune --volumes -f -a

clean: down
	-docker volume rm -f $(VOLUMES)
	sudo rm -rf /home/$(HOST_USER)/data

cleanboot: down
	-docker volume rm -f $(VOLUMES)
	-docker rmi -f nginx wordpress mariadb

re: fclean compose

.PHONY: all compose start stop down ps check fclean clean cleanboot re
