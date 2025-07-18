# Evaluación de Born2beRoot
## Ronda intensa de preguntas
* **¿Qué es una máquina virtual?**
	Es un software que permite correr varios sistemas operativos dentro de un sistema usando el mismo hardware
* **¿Cuál ha sido tu elección de sistema operativo?**
	He elegido Debian, porque es más popular, lo que quiere decir que hay más soporte en los foros, además es muy estable y general-purpose.
* **Diferencias entre Rocky y Debian**
	Rocky es parecido a Red Had Enterprise o algo así, es código abierto, pero últimamente pertenece a una empresa y, a pesar de ser también general-purpose, está más enfocado a servidores. Y usa el gestor de paquetes rpm. 
Mientras, Debian usa apt y está más enfocado al uso del usuario.
* **Propósito de una máquina virtual**
	1. Distro shopping, para probar distintas distribuciones de sistemas operativos
	2. Usar sistemas y deprecated software sin necesidad de comprar nuevo software
	3. Permite correr aplicaciones no nativas, por ejemplo, juegos de windows en Linux sin necesidad de instalarse windows
* **Diferencia entre aptitude y apt**
	Ambos son gestores de paquetes, pero aptitude gestiona automáticamente las dependencias de los paquetes, tal que al eliminar el paquete elimina automátiacamente las dependencias. Apt tiene una opción parecida, `autoremove` pero lo tienes que ejecutar manualmente igualmente...
* **¿Qué es AppArmor?**
	Es un sistema de control de acceso que gestiona los permisos de las aplicaciones y procesos. Por ejemplo, un software de grabadora de voz... pues obviamente no le vas a dejar acceder a la cámara; bueno, pues eso lo gestiona AppArmor, que está instalado de forma predeterminada en Debian, al menos.

## Verificar el funcionamiento de los servicios importantes
Que se puede hacer mediante `service ssh status` ó `systemctl status ssh`

## Gestionar usuarios
* Podemos obtener infomación de los usuarios de un grupo haciendo `getent group [nombre_grupo]`
* Los demás comandos son muy intuitivos: `adduser`, `addgroup`, `delgroup`, `deluser`
* Para cambiar la duración de la contraseña y todo eso, `chage [options] LOGIN` o si no, en el archivo `/etc/login.defs`
* Para cambiar la política de contraseña, cambiar la contraseña en `/etc/pam.d/common-password`
* **¿Por qué querríamos una política de contraseña fuerte**
	La pregunta es, por qué no, nos hemos asegurado al mínimo que los hackers no puedan infiltrarse al sistema, mediante ufw y deshabilitando la opción root del ssh, sin embargo, colocando una política de contraseña fuerte, evitamos que puedan infiltrarse aún más mediante fuerza bruta. Aunque, si la contraseña fuera gibberish, también sería difícil para nosotros recordarla.

## Cambiar el hostname
Hay dos formas de hacerlo
1. Opción: con el comando `hostnamectl set-hostname [nombre]`
2. Opción: editar los archivos `/etc/hostname`(y por si acaso, mirar `/etc/hosts`)
Recuerda rebootear el sistema posteriormente.

## Revisar particiones
Con el comando `lsblk`
* **¿Qué es LVM**
	Significa "Logical Volume Manager", se trata de un software que parte de forma abstracta el disco ó discos, es decir, los divide, pero estableciendo un límite no físico, lo que posibilita redimensionar el disco sin necesidad de interrumpir el funcionamiento del mismo.

## Revisar el sudo
Para saber si está bien instalado, usar `dpkg -s sudo`
*Nota*: No es TTY si su stdin no es una terminal

## Siguientes pasos
Para los siguientes pasos es bastante sencillo
* Firewall: `ufw` y lo que sea que quieras hacer después
* SSH: Principalmente es crear un nuevo usuario usando las instrucciones de arriba y después conectarte, por lo demás, la configuración es verificable en `etc/ssh` en los archivos `ssh_config` y `sshd_config`
* Crontab: `crontab -u [user] -e`, para pararlo o iniciarlo, usar `/etc/init.d/cron start`