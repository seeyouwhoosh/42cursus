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

#include <stdio.h> // perror
#include <unistd.h> // access & execve & dup2 & close & fork
#include <sys/wait.h> // PID_t
#include <stdlib.h> // free & malloc
#include <fcntl.h> // open


/* Get environmental variable PATH from the third argument of the main,
char **env */
char	*get_path(char *cmd, char **env)
{
	size_t	i;
	char	**split_paths;
	char	*pathplus;
	char	*path;
	int		n_paths;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5) && env[i][0] != 'P')
		i++;
	if (env[i] == NULL)
		perror("No PATH environmental variable found");
	split_paths = ft_split(env[i] + 5, ':');
	n_paths = ft_strwords(env[i], ':');
	i = -1;
	while (split_paths[i++])
	{
		pathplus = ft_strjoin(split_paths[i], "/");
		path = ft_strjoin(pathplus, cmd);
		free(pathplus);
		if (!access(path, X_OK))
			return (path);
		free(path);
	}
	ft_freesplit(split_paths, n_paths);
	return (perror("No command found"), NULL);
}

/* Execute program */
void	exec(char *cmd, char **env)
{
	char	*path;
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	path = get_path(split_cmd[0], env);
	execve(path, split_cmd, env);
	ft_freesplit(split_cmd, ft_strwords(cmd, ' '));
	free(path);
}

void	child_process(char **av, char **env, int *pipe)
{
	int	f1;

	f1 = open(av[1], O_RDONLY);
	dup2(f1, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	printf("He llegado hasta aquí\n");
	exec(av[2], env);
}

void	parent_process(char **av, char **env, int *pipe)
{
	int	f2;

	f2 = open(av[4], O_RDONLY | O_CREAT);
	dup2(f2, STDOUT_FILENO);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	// Error
	if (ac != 5)
		return (perror("Number of arguments invalid"), 1);
	// pipe
	if (pipe(fd))
		perror("Pipe's not good");
	// subprocesos
	pid = fork();
	if (pid == -1)
		perror("On fork()");
	else if (pid == 0)
		child_process(av, env, fd),;
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		child_process(av, env, fd);
	}
	return (0);
}
