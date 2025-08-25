/*

Inserte header

*/

#include "pipex.h"

#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	if (ac != 5)
		exit(1);

	int f1_access = access(av[1], R_OK);
	if (f1_access)
		perror(strerror(f1_access));
	int f1 = open(av[1], O_RDONLY);
	dup2(f1, STDIN_FILENO);

	int f2_access = access(av[ac], W_OK);
	if (f2_access)
		perror(strerror(f1_access));
	int f2 = open(av[ac], O_WRONLY); // O_APPEND si fuera >>
	dup2(f2, STDOUT_FILENO);


	int	pipefd[2];

	pipefd[1] = f2; // en principio lo dejamos así, pero lo que realmente me gustaría hacer es redirigirlo por comandos
	if (pipe(f2))
		perror("Pipe's not good");
	int i = 2;
	while (i < ac)
	{
		pid_t pid = fork();
		waitpid(pid, NULL, 0);
		i++;
	}
	return (0);
}
