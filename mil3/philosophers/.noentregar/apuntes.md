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
  * pthread_create
  * pthread_detach
  * pthread_join
  * pthread_mutex_init
  * pthread_mutex_destroy
  * pthread_mutex_lock
  * pthread_mutex_unlock

# pthreads
Creo que un buen paso sería entender cómo funciona pthread
* https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html