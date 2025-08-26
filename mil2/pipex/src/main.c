/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:30:34 by xwu               #+#    #+#             */
/*   Updated: 2025/08/26 13:46:32 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int ac, char **av, char **env)
{
	// Error
	if (ac != 5)
		exit(1);
	
	// Files checking and redirecting, tmp
	int f1_access = access(av[1], R_OK);
	if (f1_access)
		perror(strerror(f1_access));
	int f1 = open(av[1], O_RDONLY);
	dup2(f1, STDIN_FILENO);

	int f2_access = access(av[ac], W_OK);
	if (f2_access)
		perror(strerror(f1_access));
	int f2 = open(av[ac - 1], O_WRONLY); // O_APPEND si fuera >>
	dup2(f2, STDOUT_FILENO);

	// piping
	int	pipefd[2];

	pipe(pipefd);
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
