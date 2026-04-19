# USER_DOC.md

## 1. Overview of the Project

This project sets up a complete web infrastructure using Docker. The stack typically includes:

- **NGINX**: Web server that handles HTTPS requests.
- **WordPress**: Website content management system.
- **MariaDB**: Database used by WordPress.

### What services are provided?

| Service    | Description |
|------------|------------|
| NGINX      | Serves the website over HTTPS (port 443) |
| WordPress  | Provides the website interface and admin panel |
| MariaDB    | Stores website data (users, posts, settings) |

---

## 2. How to Start and Stop the Project

### Start the project

From the root of the project:

```bash
make
```

This will:

* Build the Docker images
* Create and start all containers

### Stop the project
```
make down
```

### Stop and remove everything (including volumes)
``` 
make fclean
```

## 3. Accessing the Website and Admin Panel
### Website

Open your browser and go to:

https://login.42.fr

You may need to accept a self-signed SSL certificate.

### WordPress Admin Panel

Access:

https://login.42.fr/wp-admin

Log in using the administrator credentials (see below).

## 4. Credentials Management
### Where are credentials stored?

Credentials are usually defined in:
* .env file
* docker-compose.yml
* Initialization scripts

### Typical credentials
**WordPress Admin**

* Username: defined in .env (e.g., WP_ADMIN_USER)
* Password: defined in secrets/db_password.txt (e.g., WP_ADMIN_PASSWORD)

**Database (MariaDB)**
* Database name: MYSQL_DATABASE
* User: MYSQL_USER
* Password: MYSQL_PASSWORD
* Root password: secrets/db_root_password.txt

**Important Notes**
* Do not share .env publicly.
* Change default credentials in production.
* Keep backups of your .env file.

## 5. Checking That Services Are Running
### Check container status

```
docker ps
```

You should see containers like:
* nginx
* wordpress
* mariadb

### Check logs

```
docker-compose logs
```
Or for a specific service:
```
docker-compose logs nginx
docker-compose logs wordpress
docker-compose logs mariadb
```
### Test services manually

**NGINX**
```sh
curl -k https://login.42.fr
```

**WordPress**

Open in browser:

https://login.42.fr

**MariaDB (inside container)**

```
docker exec -it mariadb mysql -u root -p
```

## 6. Troubleshooting
### Common issues
* Port already in use
	*	Stop other services using port 443
* Website not loading
	* Check NGINX logs
	* Verify containers are running
* Database connection error
	* Ensure MariaDB container is healthy
	* Check credentials in .env
## 7. Useful Commands
```sh
make            # Build and start containers
make down       # Stop containers
make re         # Rebuild everything
make fclean     # Remove containers, images, volumes
docker ps       # List running containers
docker logs <container_name>
```

## 8. Notes for Administrators

* Always verify containers are healthy after startup.
* Monitor logs regularly.
* Backup database volumes periodically.
* Keep Docker images updated if required.