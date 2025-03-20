DOCKERFILE = "docker-compose.yaml"

all: up

up:
	docker compose -f $(DOCKERFILE) up --build --detach

down:
	docker compose -f  $(DOCKERFILE) down

debug:
	docker compose -f  $(DOCKERFILE) up --build 

fclean: down
	docker system prune --all --force
	docker volume prune --all --force

re: fclean all

.PHONY: all up down debug fclean
