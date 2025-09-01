/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:30:34 by xwu               #+#    #+#             */
/*   Updated: 2025/08/31 22:58:22 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *cmd, char **env)
{
	int		fd[2];
	pid_t	command;

	if (pipe(fd))
		return (perror("Pipe failed"));
	command = fork();
	if (command == -1)
		return (perror("Fork failed"));
	if (!command)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		exec(cmd, env);
	}
	else if (command > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		waitpid(command, NULL, 0);
	}
}

void	here_doc(char *limiter)
{
	pid_t	read;
	int		fd[2];

	if (pipe(fd))
		return (perror("Pipe failed"));
	read = fork();
	if (!read)
	{
		close(fd[0]);
		here_doc_put(limiter, fd[1]);
		dup2(fd[1], STDOUT_FILENO);
	}
	else if (read > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(read, NULL, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	outfile;
	int	infile;

	if (ac < 5)
		return (write(2, "args\n", 5));
	if (!(strcmp(av[1], "here_doc")))
	{
		if (ac < 6)
			return (write(2, "args\n", 5));
		i = 2;
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		here_doc(av[2]);
	}
	else
	{
		i = 1;
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		infile = open(av[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
	}
	while (++i < ac - 2)
		child_process(av[i], env);
	dup2(outfile, STDOUT_FILENO);
	exec(av[ac - 2], env);
}
