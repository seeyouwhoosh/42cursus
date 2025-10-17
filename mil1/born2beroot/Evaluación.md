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
Que se puede hacer mediante `service ssh status` ó `systemctl status ssh` para el servicio ssh

## Gestionar usuarios
* Podemos obtener infomación de los usuarios de un grupo haciendo `getent group [nombre_grupo]`
* Los demás comandos son muy intuitivos: `adduser`, `addgroup`, `delgroup`, `deluser`
* Para cambiar la duración de la contraseña y todo eso, `chage [options] LOGIN` o si no, en el archivo `/etc/login.defs`
* Para cambiar la política de contraseña segura, cambiar cosas en `/etc/pam.d/common-password`
* **¿Por qué querríamos una política de contraseña fuerte**
La pregunta es, por qué no, nos hemos asegurado al mínimo que los hackers no puedan infiltrarse al sistema, mediante ufw y deshabilitando la opción root del ssh, sin embargo, colocando una política de contraseña fuerte, evitamos que puedan infiltrarse aún más mediante fuerza bruta. Aunque, si la contraseña fuera gibberish, también sería difícil para nosotros recordarla.

```sh
password [success=1 default=ignore] pam_succeed_if.so user != root
#Se ejecuta 1 línea de abajo en caso de que el usuario no sea root

password requisite pam_pwquality.so difok=7
#La contraseña debe tener al menos 7 caracteres distintos a la contraseña antigua

password requisite pam_pwquality.so retry=3 minlen=10 dcredit=-1
ucredit=-1 lcredit=-1 maxrepeat=3 usercheck=1 enforce_for_root
#credit: máximo de caracteres  >= 0; mínimo de caracteres <0
#maxrepeat: caracteres iguales consecutivos
```

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
* Para saber si está bien instalado, usar `dpkg -s sudo` o `which sudo`
* Para añadir usuarios que están en sudo, ver qué usuarios están... usar comandos para gestionar usuarios (`getent group [nombre_grupo]` y similares: `adduser`, `addgroup`, `delgroup`, `deluser`)
* El archivo de reglas para los sudoers están en `etc/sudoers.d/sudo_config`
*Nota*: No es TTY si su stdin no es una terminal

```sh
Defaults  passwd_tries=3
# sudo a 3 intentos

Defaults  badpass_message="Mensaje de error personalizado"
# Mensaje si está la contraseña mal

Defaults  logfile="/var/log/sudo/sudo.log"
#Dónde quedan registradas la información sobre el sudo

Defaults  log_input,log_output
#Registrar el input y output de los comandos

Defaults  iolog_dir="/var/log/sudo"
#Dónde se almacenan los inputs y outputs

Defaults  requiretty
#Solo se permitirá el uso de sudo cuando hay una tty real 

Defaults  secure_path
"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
#Sitios en los que no se puede usar sudo

```

## Siguientes pasos
Para los siguientes pasos es bastante sencillo
* **Firewall**: comando `ufw` (mirar `ufw help` si eso)
  * `allow`, `status`, `delete`
* **SSH** (Secure Shell): Principalmente es crear un nuevo usuario usando las instrucciones de arriba y después conectarte desde una terminal fuera de la máquina virtual, por lo demás, la configuración es verificable en `etc/ssh` en los archivos `ssh_config` y `sshd_config`
* **Crontab**: `crontab -u [user] -e`, para pararlo o iniciarlo, usar `/etc/init.d/cron start` / `/etc/init.d/cron stop`
  * **¿Qué es crontab?**: administrador de procesos en segundo plano que corre un comando shell periódicamente
  * **Formato del crontab**: minuto hora día mes díadelasemana comando/script
    * Ejemplos:
      * */10 (cada 10 minutos) * * * *
      * */1 (cada minuto) * * * *