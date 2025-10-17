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
   2. crear archivo sudo_config en /etc/sudoers.d
   ```sh
   Defaults  passwd_tries=3
   Defaults  badpass_message="Upsies, wrong password, silly."
   Defaults  logfile="/var/log/sudo/sudo.log"
   Defaults  log_input,log_output
   Defaults  iolog_dir="/var/log/sudo"
   Defaults  requiretty
   Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
   ```
5. Política de contraseña
      1. La expiración de contraseña y fechas así se cambia con `chage`y las correspondientes opciones
         1.  expirar cada 30 días
         2.  número mínimo de días permitido antes de modificar una contraseña deberá ser 2
         3.  mensaje de aviso 7 días antes de que su contraseña expire
      2. Alternativa: editar /etc/var/login.defs
      3.  Calidad de la contraseña
          1.  sudo apt install libpam-pwquality
          2.  En /etc/pam.d/common-password:
            ```
   password [success=1 default=ignore] pam_succeed_if.so user != root
   password requisite pam_pwquality.so difok=7
   password requisite pam_pwquality.so retry=3 minlen=10 dcredit=-1 ucredit=-1 lcredit=-1 maxrepeat=3 usercheck=1 enforce_for_root
            ```
1. Cambio de nombre de host
   1. Archivos a cambiar: /etc/hostname y /etc/hosts
   2. Reboot
## Monitoreo

Cuando el servidor inicie, el script mostrará cierta información (listada debajo) en
todos los terminales cada 10 minutos (Échale un vistazo a wall). El banner de wall es opcional. Ningún error debe ser visible


1. La arquitectura de tu sistema operativo y su versión de kernel.
```sh
uname --all
```
2. El número de núcleos físicos.
```sh
grep "physical id" /proc/cpuinfo | wc -l
```
```ssh
grep "cpu cores" /proc/cpuinfo | awk 'END{print $4}'
```
3. El número de núcleos virtuales.
```sh
grep "processor" /proc/cpuinfo | wc -l
```
```sh
nproc
```
4. La memoria RAM disponible actualmente en tu servidor y su porcentaje de uso.
```sh
free --mega | awk '$1 == "Mem:" {print $4}'
free --mega | awk '$1 == "Mem:" {printf("%0.2f", $3/$2*100)}'
```
5. La memoria disponible actualmente en tu servidor y su utilización como un porcentaje.
```sh
df -h --total | grep total | awk '{print $4}'
df -h --total | grep total | awk '{print $5}'
```
6. El porcentaje actual de uso de tus núcleos.
```sh
top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%", $2 + $4)}'
```
7. La fecha y hora del último reinicio.
```sh
who -b | awk '{print $3 " " $4}'
```
8. Si LVM está activo o no.
```sh
if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi
```
9.  El número de conexiones activas.
```sh
grep TCP /proc/net/sockstat | awk '{print $3}'
```
10. El número de usuarios del servidor.
```sh
who | wc -l
```
12. La dirección IPv4 de tu servidor y su MAC (Media Access Control)
```sh
hostname -I | awk '{print $1}'
ip link show | grep link/ether | awk '{print $2}'
```
13. El número de comandos ejecutados con sudo.
```sh
cat /var/log/sudo/sudo.log | grep USER | wc -l
```
### sh file
```sh
#!/bin/bash
ARCH=$(uname --all)

PCPU=$(grep "physical id" /proc/cpuinfo | wc -l)

VCPU=$(grep "processor" /proc/cpuinfo | wc -l)

RAM_TOTAL=$(free -h | grep Mem | awk '{print $2}')
RAM_USED=$(free -h | grep Mem | awk '{print $3}')
RAM_PERC=$(free -k | grep Mem | awk '{printf("%.2f%%", $3/$2*100)}')

DISK_TOTAL=$(df -h --total | grep total | awk '{print $2}')
DISK_USED=$(df -h --total | grep total | awk '{print $3}')
DISK_PERC=$(df -k --total | grep total | awk '{print $5}')

CPU_LOAD=$(top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%%"), $2 + $4}')

LAST_BOOT=$(who -b | awk '{print($3 " " $4)}')

LVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)

TCP=$(grep TCP /proc/net/sockstat | awk '{print $3}')

USER_LOG=$(who | wc -l)

IP_ADDR=$(hostname -I | awk '{print $1}')

MAC_ADDR=$(ip link show | grep link/ether | awk '{print $2}')

SUDO_LOG=$(cat /var/log/sudo/sudo.log | grep USER | wc -l)

wall "   # Architecture:    $ARCH
   # Physical CPUs:   $PCPU
   # Virtual CPUs:    $VCPU
   # RAM usage:       $RAM_USED/$RAM_TOTAL ($RAM_PERC)
   # Disk usage:      $DISK_USED/$DISK_TOTAL ($DISK_PERC)
   # CPU load:        $CPU_LOAD
   # Last boot:       $LAST_BOOT
   # LVM use:         $LVM
   # TCP connections: $TCP established
   # Users logged:    $USER_LOG
   # Network:         IP $IP_ADDR ($MAC_ADDR)
   # Number of sudos: $SUDO_LOG cmd"
```