/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:30:34 by xwu               #+#    #+#             */
/*   Updated: 2025/08/28 22:44:36 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **env)
{
	size_t	i;
	char	**split_paths;
	char	*pathplus;
	char	*path;

	i = -1;
	while (env[++i] && !ft_strnstr(env[i], "PATH=", 5))
		;
	if (env[i] == NULL)
		perror("PATH");
	split_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (split_paths[++i])
	{
		pathplus = ft_strjoin(split_paths[i], "/");
		path = ft_strjoin(pathplus, cmd);
		free(pathplus);
		if (!access(path, X_OK))
			return (ft_freesplit(split_paths, ft_strwords(env[i], ':')), path);
		free(path);
	}
	ft_freesplit(split_paths, ft_strwords(env[i], ':'));
	write(2, cmd, ft_strlen(cmd));
	write(2, ": Command not found\n", 20);
	return (0);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**split_cmd;

	split_cmd = ft_split(cmd, ' ');
	path = get_path(split_cmd[0], env);
	if (!path)
		exit(1);
	if (execve(path, split_cmd, env))
		perror(path);
	ft_freesplit(split_cmd, ft_strwords(cmd, ' '));
	free(path);
}

void	child_process(char **av, char **env, int *pipe)
{
	int	f1;

	f1 = open(av[1], O_RDONLY);
	if (f1 <= -1)
	{
		perror(av[1]);
		exit(1);
	}
	dup2(f1, STDIN_FILENO);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[0]);
	exec(av[2], env);
}

void	parent_process(char **av, char **env, int *pipe)
{
	int	f2;

	f2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (f2 <= -1)
	{
		perror(av[4]);
		exit(1);
	}
	dup2(f2, STDOUT_FILENO);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	char	*error_msg;

	error_msg = "pipex simulates \033[1m< infile cmd1 | cmd2 > outfile\033[0m\n\
Correct usage:\033[1m ./pipex infile cmd1 cmd2 outfile\033[0m\n";
	if (ac != 5)
		return (write(2, error_msg, ft_strlen(error_msg)));
	if (pipe(fd))
		return (perror("Pipe failed"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("Fork failed"), 1);
	else if (pid == 0)
		child_process(av, env, fd);
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		parent_process(av, env, fd);
	}
	return (0);
}
