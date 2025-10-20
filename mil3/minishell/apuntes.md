## Funciones externas permitidas
```c
#include <stdio.h>
int printf(const char *restrict format, ...);
/*
@ Cuando ocurre un error, imprime "el coso: el mensaje del error asignado", el mensaje 
varía según el ERRNO
*/
void perror(const char *s);

#include <stdlib.h>
void *malloc(size_t size);
void free(void *ptr);
void exit(int status);

/* 
@ Para conseguir el contenido del environment, principalmente creo que PATH y supongo que todo
lo demás si hay que imitar el comportamiento de echo
*/
char *getenv(const char *name);

#include <fcntl.h>
int open(const char *pathname, int flags, mode_t mode);

#include <unistd.h>

/*
@ Mira si los permisos de un archivo son correctos
@ int mode: Bitwise-inclusive OR of the access permissions to be checked (R_OK, W_OK, X_OK)
or the existence test (F_OK)
@ return: 0 si no hay ningún problema, -1 otherwise, que hay específicos, según definidos
*/
int access(const char *pathname, int mode);
ssize_t write(int fildes, const void *buf, size_t nbyte);
ssize_t read(int fildes, void *buf, size_t nbyte);
int close(int fildes);

/*
@ El absolute path al current working directory, pero solo para el proceso, es decir, no
altera realmente la localización de la termina actual
*/
char *getcwd(char *buf, size_t size);

/*
@ Es como un "cd", funciona para ".."
*/
int chdir(const char *path);

/*
@ Se crea una copia del proceso activo. PID adopta un valor (el identificador del proceso
hijo), hace lo que tiene que hacer como si fuera un programa aparte (puedes hacer exit)
compartiendo variables del proceso que se ha copiado antes. Por lo que entiendo, cuando
termina el proceso, regresa al proceso padre con el PID, no se mantienen las variables
cambiadas. Relevante para hacer exec de algún tipo
*/
pid_t fork(void);
int execve(const char *path, char *const _Nullable argv[], char *const _Nullable envp[]);
int dup(int fildes);
int dup2(int fildes, int fildes2);
int pipe(int fildes[2]);

/*
@ find the pathname of a terminal associated with the file descriptor
*/
char *ttyname(int fildes);

/*
@ En qué slot está la terminal actual, pero creo que hoy en día está prácticamente deprecated
*/
int ttyslot(void);

/*
@ Básicamente eliminar lo que sea que tenga ese nombre, si hay algún proceso con el archivo abierto, espera a que acabe antes de eliminarlo
*/
int unlink(const char *path);

#include <dirent.h>
DIR *opendir(const char *dirname);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);

#include <sys/wait.h>
pid_t wait(int *stat_loc);
pid_t waitpid(pid_t pid, int *stat_loc, int options);
pid_t wait3(int *_Nullable wstatus, int options, struct rusage *_Nullable rusage);
pid_t wait4(pid_t pid, int *_Nullable wstatus, int options, struct rusage *_Nullable rusage);

#include <signal.h>
void (*signal(int sig, void (*func)(int)))(int);
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
int sigemptyset(sigset_t *set);
int sigaddset(sigset_t *set, int signo);
int kill(pid_t pid, int sig);

#include <sys/stat.h>
int stat(const char *restrict path, struct stat *restrict statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *restrict path, struct stat *restrict statbuf);


#include <string.h>
char *strerror(int errnum)

#include <sys/iotcl.h>
int ioctl(int fd, unsigned long op, ...);

#include <readline/readline.h>
char *readline(const char *prompt);
void add_history(const char *line);
void rl_clear_history();
int rl_on_new_line();
void rl_replace_line (const char *text, int clear_undo);
void rl_redisplay();

#include <term.h>
int tgetent(char *bp, const char *name);
int tgetflag(const char *id);
int tgetnum(const char *id);
char *tgetstr(const char *id, char **area);
char *tgoto(const char *cap, int col, int row);
int tputs(const char *str, int affcnt, int (*putc)(int));


#include <termios.h>
int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);
int tcgetattr(int fildes, struct termios *termios_p);
```

## Guidelines generales
* La minishell no implementa 