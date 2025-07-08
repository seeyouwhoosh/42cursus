Objetivo: Entregar "signature.txt

# Virtual Machine Setup
## Debian Vs Rocky
Debian parece el más estable entre los sistemas operativos (yes). Es bastante general-purpose

Rocky no es una distribución muy conocida... (al menos yo no la conozco), pero al parecer, es como el Red Hat pero open source, algo que ya había sido algo parecido CentOS. En lo que más difiere con Debian es en package management, que usa rpm.

Al parecer linux mint es más ligero que Ubuntu, yay. Me hace demasiada gracia lo elitista que es Arch, "there is bit of a learning curve", the learning curve that leads to your demise.

## Configuración inicial

1. Hostname: xwu42
2. Particiones de discos
   1. Nomenclatura de particioones
      1. "sda1", sigue el formato "sd" + X + N, siendo X la letra del volumen y N el número de partición del volumen.
   2. ¿Qué es LVM?
      1. Significado de las siglas: Logical Volume Manager
      2. Gestiona el almacenamiento de forma flexible y dinámica, no requiere que el sistema se detenga puesto que crea espacios abstractos
      3. Particiones comunes del sistema 
         1. /swap (1GB)
         2. /home (encriptar)
         3. /boot (1GB; creo que este no es necesario)
         4. /root (3GB; encriptar)
	3. Grub boot loader
      1. ¿Qué es grub?
      2. ¿Qué es kernel?

## Configuración del sistema

0. Actualizar paquetes del sistema: `apt update && apt upgrade`
   1. ¿Qué es apt? ¿Y qué es aptitude? APT = Advanced Package Tool. Ambos son gestores de paquetes, pero Aptitude tiene interfaz visual, recuerda lo que es dependencia y lo que es instalación directa (y de la misma forma, elimina las dependencias junto con el paquete principal; apt tiene el comando `autoremove`). 
1. Configuración de usuario
   1. Para ser root: `su`
   2. `apt install sudo` & reboot
   3. Para crear usuario: `adduser [usuario]` (spoiler: para eliminar el user del)
   4. Crear grupo: `addgroup [grupo]` (comprobar con `getent group`)
      1. sudo
      2. user42
   5. Añadir usuario a grupo: `adduser [usuario] [grupo]`
   ```sh
   su
   apt install sudo
   addgroup user42
   adduser xwu user42
   adduser xwu sudo
   ```
2. ssh
   1. Comprobar si está con `service ssh status`
   2. Si no está, instalar el openssh-server
   3. Cambiar puerto a 4242 tanto de escucha como de respuesta
   4. PermitRootLogin no
   5. Hay Port Forwarding en en virtual machine xd
   ```sh
   service ssh status
   apt install openssh-server
   cd /etc/ssh
   nano sshd_config
   ```
3. ufw
   1. `ufw enable`
   2. `ufw allow 4242`
   ```sh
   ufw enable
   ufw allow 4242
   ```
4. Política de sudo
   1. mkdir /var/log/sudo para almacenar logs
   2. crear archivo sudo_config en /etc/sudoerd.d
   ```sh
   Defaults  passwd_tries=3
   Defaults  badpass_message="Mensaje de error personalizado"
   Defaults  logfile="/var/log/sudo/sudo_config"
   Defaults  log_input, log_output
   Defaults  iolog_dir="/var/log/sudo"
   Defaults  requiretty
   Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
   ```

5. Política de contraseña
      1. Se cambia con `chage`y las corrrespondientes opciones
         1.  expirar cada 30 días
         2.  número mínimo de días permitido antes de modificar una contraseña deberá ser 2
         3.  mensaje de aviso 7 días antes de que su contraseña expire
6. Cambio de nombre de host
   1. 
7. Monitoreo
   1. 
8. Pasos finales
https://born2beroot-tracking.pages.dev/
https://42-cursus.gitbook.io/guide/1-rank-01/born2beroot/install-your-virtual-machine
https://noreply.gitbook.io/born2beroot/virtual-machine-setup/sudo-policies

1. ¿Qué es SELinux?

2. ¿Qué es AppArmor?

3.  ¿Cuál es la diferencia entre aptitude y apt?

4.  ¿Cómo se implementa una política de contraseñas?

5.  ¿Cómo se modifica el hostname de la máquina?


8.  ¿Qué es modo TTY?

9.  ¿Qué es wall?

10. ¿Qué es UTM?
