# Funciones permitidas
## Funciones que ya conocía
* <stdio.h>:
	* printf
* <stdlib.h>
	* malloc
	* free
* <unistd.h>
	* write
## Funciones que no conocía (o de los que no estaba muy segura de cómo funcionan)
* <string.h>
	* `void *memset(void *s, int c, size_t n);`: fills the first n bytes of the memory area pointed to by s with the constant byte c.
* <unistd.h>
	* `int usleep(useconds_t usec);`: suspends the execution of the calling thread for a minimun of usec microseconds.
* <sys/time.h>
	* `int gettimeofday(struct timeval *tv, struct timezone *tz);`: gives the time since Epoch (1970-01-01 00:00:00+0000 (UTC)).
	```c
	struct timeval {
		time_t      tv_sec;     /* seconds */
		suseconds_t tv_usec;    /* microseconds */
	};
	struct timezone {
		int tz_minuteswest;     /* minutes west of Greenwich */
		int tz_dsttime;         /* type of DST correction, DST_MET para nosotros*/
	};
	```
* <pthread.h>
	* **pthread_create**
	```c
	/*
	* The function returns 0 on sucess; 
	*    EAGAIN with insufficient resources;
	*    EINVAL with invalid settings;
	*    EPERM  with no permission to set information
	*/
	int pthread_create
				(pthread_t *thread, 
				const pthread_attr_t *attr, // Not really important
				void *(*start_routine) (void *), // Función ejecutadora que tiene que ser del tipo `
				void *arg); //argumentos que se pasan
	```
	* **pthread_join**: esperar a que el thread termine de ejecutarse y almacenar el valor de return en retval
	```c
	int pthread_join(
					pthread_t thread, 
					void **retval); // dónde colocar el valor que se devuelve
	```
	* pthread_mutex_init
	* pthread_mutex_destroy
	* pthread_mutex_lock
	* pthread_mutex_unlock

# pthreads
Creo que un buen paso sería entender cómo funciona pthread
* https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html

## Concepto de mutexes
Los mutex ó cerrojos bloquean a los threads el acceso de variables. Esto para prevenir uno de los problemas al manejar threads: **data races**.

Cuando dos o más threads necesitan acceder a un mismo espacio de memoria, casi como cuando dos personas colaboradoras intentan hacer push simultáneamente a una misma rama.

Otro aspecto a tener en cuenta es que las funciones que llaamos tiene que ser **thread safe**, es decir, no hay variables globales o estáticas (que no están protegidas); y no devuelve punteros a memoria estática interna

Y por último, el **deadlock**: cuando un mutex se aplica, pero no se desbloquea. De esta forma, la ejecución del programa es pausada indefinidamente.