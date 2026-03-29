*This project has been created as part of the 42 curriculum by xwu.*

# Inception

## Description

The **Inception** project is part of the 42 curriculum and focuses on system administration using Docker.  
Its goal is to broaden understanding of virtualization, containerization, and infrastructure deployment by building a small but complete web environment composed of multiple services.

This project consists of creating a secure and modular infrastructure using **Docker Compose**, where each service runs in its own container. The system typically includes:

- A **NGINX** web server acting as a reverse proxy
- A **WordPress** website running with PHP-FPM
- A **MariaDB** database
- Persistent storage using Docker volumes

The main objective is to understand how services communicate in a containerized environment and how to properly configure them in a reproducible and isolated way.

---

## Project Description (Docker & Design Choices)

This project is entirely based on **Docker** and **Docker Compose**, ensuring portability, isolation, and reproducibility of the entire infrastructure.

### Docker usage in this project

Each service is built as a separate container:

- **NGINX container**: handles HTTPS traffic and acts as a reverse proxy
- **WordPress container**: serves the dynamic website using PHP-FPM
- **MariaDB container**: manages the database backend
- **Volumes**: ensure data persistence for WordPress files and database content
- **Network**: allows secure communication between containers without exposing internal services directly

### Main design choices

- Each service runs in its own container for **separation of concerns**
- Only the **NGINX container is exposed externally**
- Internal communication is handled via a **Docker bridge network**
- Data persistence is ensured using **named Docker volumes**
- Configuration is automated using **Dockerfiles and docker-compose.yml**
- Environment variables are used for configuration and secret injection (no hardcoded credentials)

---

### Virtual Machines vs Docker

| Aspect | Virtual Machines | Docker |
|------|------------------|--------|
| OS | Full guest OS | Shares host kernel |
| Performance | Heavier, slower boot | Lightweight, fast startup |
| Isolation | Strong isolation | Process-level isolation |
| Resource usage | High | Efficient |

Docker is preferred here for its lightweight nature and fast deployment capabilities.

---

### Secrets vs Environment Variables

- **Environment variables**: used for configuration values like database names, users, and passwords in a simple setup.
- **Secrets**: more secure method for sensitive data (not fully implemented in this project but important conceptually).

In production systems, secrets are preferred because they are not exposed in process lists or environment dumps.

---

### Docker Network vs Host Network

- **Docker bridge network (used in this project)**:
  - Containers communicate via internal DNS
  - Services are isolated from host network
  - More secure and controlled

- **Host network**:
  - Container shares the host’s network stack
  - Higher performance but less isolation
  - Not used here due to security concerns

---

### Docker Volumes vs Bind Mounts

- **Volumes (used in this project)**:
  - Managed by Docker
  - More secure and portable
  - Ideal for databases and persistent data

- **Bind mounts**:
  - Direct mapping to host filesystem
  - Useful for development
  - Less portable and more error-prone

---

## Instructions

### 1. Prerequisites

Ensure the following are installed:

- Docker
- Docker Compose

### 2. Build the project

```bash
make
```
or manually:

```sh
docker-compose up --build
```
### 3. Run the project
```sh
make up
```
or:
```
docker-compose up
```
### 4. Stop the project
```sh
make down
```
### 5. Clean all containers, images, and volumes
```sh
make clean
```
## Resources
### Official Documentation
https://docs.docker.com/
https://docs.docker.com/compose/
https://nginx.org/en/docs/
https://mariadb.com/kb/en/
https://www.php.net/docs.php

### Tutorials and References
* Docker in Practice – Nigel Poulton
* "Docker and Kubernetes: The Complete Guide" (Udemy / Stephen Grider)
* 42 Inception subject PDF
* Linux networking and containerization articles
* 
### AI Usage

AI tools were used in this project for:
* Structuring the README.md according to 42 requirements
* Improving readability and formatting of documentation

No AI was used to generate core implementation code or configuration logic.
