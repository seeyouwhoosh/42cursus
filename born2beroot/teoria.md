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
1. Configuración de usuario
   1. Para ser root: `su`
   2. `apt install sudo` & reboot
   3. Para crear usuario: `adduser [usuario]` (spoiler: para eliminar el user del)
   4. Crear grupo: `addgroup [ grupo]` (comprobar con `getent group`)
      1. sudo
      2. user42
   5. Añadir usuario a grupo: `adduser [usuario] [grupo]`
2. ssh
   1. Comprobar si está con `service ssh status`
   2. Si no está, instalar el openssh-server
   3. Cambiar puerto a 4242 tanto de escucha como de respuesta
   4. PermitRootLogin no
   5. Hay Port Forwarding en en virtual machine xd
3. ufw
   1. `ufw enable`
   2. `ufw allow 4242`

4. ¿Qué es SELinux?

5. ¿Qué es AppArmor?

6. ¿Cómo se cifra una partición?

7.  ¿Cuál es la diferencia entre aptitude y apt?

8.  ¿Debería permitir loguearme con contraseña o solo con ssh?

9.  ¿Cómo se implementa una política de contraseñas?

10. ¿Cómo se modifica el hostname de la máquina?

11. ¿Cómo creo un usuario y le asigno un grupo?

12. ¿Qué es modo TTY?

13. ¿Qué es wall?

14. ¿Qué es UTM?
