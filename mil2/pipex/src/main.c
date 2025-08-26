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
	int		fd[2];
	pid_t	pid;
	int		*status;

	// Error
	if (ac != 5)
		perror("Number of arguments invalid");
	// pipe
	if (pipe(fd))
		perror("Pipe's not good");
	// subprocesos
	pid = fork();
	if (pid == -1)
		perror("Error on fork()");
	else if (pid == 0)
		child_process();

	waitpid(pid, status, 0);
	parent_process();
	return (0);
}
