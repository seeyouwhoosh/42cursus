/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:30:34 by xwu               #+#    #+#             */
/*   Updated: 2025/08/31 21:26:04 by xwu              ###   ########.fr       */
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

	f2 = open(av[4], O_WRONLY | O_CREAT, 0777);
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

void	here_doc(char *limiter, int *fd)
{
	char	*input;
	int		read;

	read = fork();
	if (!read)
	{
		close(fd[0]);
		input = get_next_line(0);
		while (input)
		{
			if (!ft_strcmp(input, limiter))
				exit(0);
			write(fd[1], input, ft_strlen(input));
			input = get_next_line(0);
		}
	}
	else if (read > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(0);
	}
	
}

char	*get_next_line(int fd)
{
	char	c;
	size_t	i;
	char	*line;
	int		nread;

	if (fd < 0)
	return (NULL);
	i = 0;
	line = malloc(9999);
	nread = read(fd, &c, 1);
	while (nread > 0)
	{
		line[i] = c;
		i++;
		if (c = '\n')
			break ;
		nread = read(fd, &c, 1);
	}
	line[i] = '\0';
	if (i == 0 || nread < 0)
		return (free(line), NULL);
	return (line);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	i;
	int	outfile;

	if (ac < 5)
		return (write(2, "args\n", 5));
	if (!(strcmp(av[1], "here_doc")))
	{
		i = 3;
		outfile = open(av[ac - 1], O_CREAT | O_TRUNC | O_APPEND, 0777);
		here_doc(av[2], fd);
	}
	else
	{
		i = 2;
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT, 0777);
	}
	while (i < ac - 2)
		child_process();
	outfile = dup2(fd[1], STDOUT_FILENO);

}
