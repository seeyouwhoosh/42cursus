# Funciones permitidas
* open
* close
* read
* write
* malloc
* free
* perror
* strerror
* access: comprueba los permisos de un archivo. F_OK tests for the
       existence of the file.  R_OK, W_OK, and X_OK test whether the file
       exists and grants read, write, and execute permissions,
       respectively.
* dup: duplica un descriptor de un archivo y devuelve el nuevo
* dup2: parecido a dup, pero puedes elegir el fd del archivo. Incluso cierra new fd con antelación. Si old fd no es válido, no se cierra. Si son iguales, no hace nada y retorna new fd
* execve: Ejecuta un programa reemplazando el proceso actual
* exit
* fork: `pid_t fork(void);`, crea un proceso hijo duplicando el actual, devuelve 0 al hijo y el pid del hijo al padre
* pipe: crea un pipe ( un canal unidireccional), que está almacenada en una estructura `long fd[2]`, en la primera posición está el modo lectura, el segundo es escritura
* unlink: elimina un archivo;
* wait: `pid_t wait(int *wstatus);` pid_t wait(int *wstatus);
* waitpid: `pid_t waitpid(pid_t pid, int *wstatus, int options);`, Como wait, pero permite elegir un hijo específico (pid) o usar flags (WNOHANG, etc).

# Cosas que no he entendido del todo de la subject
* ¿Y si uso pipes en los argumentos? ¿O si lo redirijo en los argumentos? O sea, realmente no sé cómo gestiono los comandos, igual los cojo, los paso por el cmd y ya está, no sé
* Para los múltiples pipes... ¿cómo sé cuándo es el file? Supongo que el primer y último de los argumentos y ya está
* WTF es "here_doc": es una forma de representar cadenas en los lenguajes de programación o shells
* Y habría que investigar más a fondo realmente cómo funcionan los pipes, los infiles y todo eso. Además, el funcionamiento de las funciones de arriba que no conozca. 

# En el proceso de entender qué demonios está pasando
```sh
< file1 cmd1 | cmd2 > file2
|			 |		|-> ">" redirección de output a un file o input stream, en este caso a file2
|			 |-> "|" redirección del output de anterior comando al input del siguiente comando
|-> "<" redirección del input, es decir, es el propio shell el que abre file1 (Más información: https://askubuntu.com/a/883822), lee el contenido y lo pasa como input stream. 
	En este caso, el contenido del file1 es redirigido al stdin, es decir, si el cmd1 lee del stdin, lo va a leer del file1, en vez del teclado
```
* ¿Por qué el formato del comando es tan raro? ¿No debería ir "< file1" primero?
	El shell construye el comando primero y luego las redirecciones, así que no importa dónde pongamos la redirección, con que sigamos el formato de "< cosoraro", el shell lo trata como el hijo pródigo...
	Luego todas las permitaciones tipo
	```sh
	< file cmd arg1 arg2
	cmd < file arg1 arg2
	cmd arg1 < file arg2
	cmd arg1 arg2 < file
	```
	son legales.

## Otros operadores interesantes
* `>>`: append
* `<<`: Lee de la stdin hasta que se encuentra con un limitador especificado

## Me ha gustado este get_next_line
```c
/* Function that will read input from the terminal and return line. */
int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

char	*get_next_line(int fd)
{
	char	*ret = malloc(9999);
	char	c;
	int		i = 0;
	int		cpt = 0;

	if (fd < 0)
		return (NULL);
	while ((cpt = read(fd, &c, 1)) > 0)
	{
		ret[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || cpt < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
}
```