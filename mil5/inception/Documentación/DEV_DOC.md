# DEV_DOC.md

## 1. Environment Setup from Scratch

### Prerequisites

Before starting, make sure the following are installed:

- Docker
- Docker Compose
- Make

Check installations:

```bash
docker --version
docker-compose --version
make --version
```

### Project Structure

```sh
inception/  
├── Makefile  
├── secrets/  
│   ├── db_password.txt  
│   └── db_root_password.txt  
└── srcs/  
    ├── docker-compose.yml  
    ├── .env  
    └── requirements/  
        ├── mariadb/  
        │   ├── Dockerfile  
        │   ├── conf/  
        │   └── tools/  
        ├── nginx/  
        │   ├── Dockerfile  
        │   ├── conf/  
        │   └── tools/  
        └── wordpress/  
            ├── Dockerfile  
            ├── conf/  
            └── tools/  
```

### Configuration Files
`.env`

This file contains all environment variables used by Docker Compose. Example:
```env
MYSQL_DATABASE=wordpress
MYSQL_USER=wpuser
MYSQL_ROOT_PASSWORD_FILE=/run/secrets/db_root_password
MYSQL_PASSWORD_FILE=/run/secrets/db_password
MYSQL_HOST=mariadb
DOMAIN_NAME=login.42.fr
```

> ⚠️ This file should NOT be committed to public repositories.

### Secrets Management
* Store sensitive data in .env
* Never hardcode credentials inside Dockerfiles
* Use strong passwords
* Restrict access to configuration files

## 2. Build and Launch the Project
### Using Makefile

Start the project:
```sh
make
```

This usually:

* Builds Docker images
* Starts containers in detached mode

### Using Docker Compose directly

```sh
docker-compose up -d --build
```

### Rebuild everything
```sh
make re
```

## 3. Managing Containers and Volumes
### Container Management

```sh
#List running containers:

docker ps

#List all containers:

docker ps -a

#Stop containers:

docker-compose down

#Restart containers:

docker-compose restart
```

### Accessing Containers

**Enter a running container:**

```sh
docker exec -it <container_name> /bin/bash
```

Example:

```sh
docker exec -it wordpress /bin/bash
```

### Logs

```sh
#View logs:

docker-compose logs

#Follow logs:

docker-compose logs -f

#Specific service:

docker-compose logs nginx
docker-compose logs wordpress
docker-compose logs mariadb
```

### Volume Management

```sh
#List volumes:

docker volume ls

#Inspect a volume:

docker volume inspect <volume_name>

#Remove unused volumes:

docker volume prune

#Remove everything (containers + volumes):

make fclean
```

## 4. Data Storage and Persistence
### Where Data is Stored

Data is stored using Docker volumes to ensure persistence.

Typical volumes:

| Service   | Volume Path (inside container) |
|----------|-------------------------------|
| MariaDB  | /var/lib/mysql                |
| WordPress| /var/www/html                |

These are mapped to Docker volumes defined in docker-compose.yml.

### Example (docker-compose.yml)
```yaml
volumes:
  mariadb_data:
  wordpress_data:
```

### Why Persistence Matters
* Data remains even if containers are stopped or removed
* Prevents data loss during rebuilds
* Allows backups and migration

### Deleting Persistent Data

To remove volumes (WARNING: deletes all data):
```sh
make fclean
```

## 5. Development Workflow Tips
* Rebuild containers after modifying Dockerfiles:
```sh
make re
```

* Check logs frequently for debugging
* Use docker exec to inspect container state
* Keep .env consistent with your configuration
* Avoid modifying files directly inside containers (use volumes instead)
## 6. Troubleshooting
Containers not starting

* Check logs:
```sh 
docker-compose logs
```
* Verify .env values
* Ensure ports are not already in use

### Database connection issues
* Confirm MariaDB container is running
* Verify credentials match between WordPress and MariaDB
* Check network configuration in Docker Compose
### Changes not applied

* Rebuild containers:
```sh
make re
```
* Clear volumes if necessary:
```sh
make fclean
```