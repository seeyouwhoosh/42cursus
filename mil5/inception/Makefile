COMPOSE_FILE = srcs/docker-compose.yml
DATA_DIR = /home/$(USER)/data

.PHONY: all build up down clean fclean re

all: build up

$(DATA_DIR)/mariadb:
	mkdir -p $(DATA_DIR)/mariadb
	sudo chown -R ${USER}:${USER} /home/${USER}/data/mariadb
	chmod 755 /home/${USER}/data/mariadb

$(DATA_DIR)/wordpress:
	mkdir -p $(DATA_DIR)/wordpress
	sudo chown -R ${USER}:${USER} /home/${USER}/data/wordpress
	chmod 755 /home/${USER}/data/wordpress

build: $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress
	@if [ ! -f srcs/.env ] || [ ! -s srcs/.env ] ; then\
		echo "There is no .env file or empty\n";\
		exit 1;\
	fi
	@if [ ! -d secrets ] || [ ! -f secrets/db_root_password.txt ] || [ ! -f secrets/db_password.txt ] || [ ! -s secrets/db_root_password.txt ] || [ ! -s secrets/db_password.txt ]; then\
		echo "No docker secrets found or empty\n";\
		exit 1;\
	fi
	docker compose -f $(COMPOSE_FILE) build

up:
	@if ! grep -q "127.0.0.1 xwu.42.fr" /etc/hosts; then\
		echo "127.0.0.1 xwu.42.fr" | sudo tee -a /etc/hosts > /dev/null;\
	fi
	docker compose -f $(COMPOSE_FILE) up -d --build

down:
	docker compose -f $(COMPOSE_FILE) down

clean:
	docker compose -f $(COMPOSE_FILE) down
	docker system prune -af

fclean: clean
	docker volume prune -f
	sudo rm -rf $(DATA_DIR)

re: fclean all