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
		close(fd[1]);
		close(fd[0]);
		exec(cmd, env);
	}
	else if (command > 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		waitpid(command, NULL, 0);
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
		if (c == '\n')
			break ;
		nread = read(fd, &c, 1);
	}
	if (nread == -1 || (!nread && !i))
		return (free(line), NULL);
	line[i] = '\0';
	return (line);
}

void	here_doc(char *limiter)
{
	char	*input;
	pid_t	read;
	int		fd[2];

	if (pipe(fd))
		return (perror("Pipe failed"));
	read = fork();
	if (!read)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		input = get_next_line(0);
		while (input)
		{
			if (!ft_strcmp(input, limiter))
			exit(0);
			write(STDOUT_FILENO, input, ft_strlen(input));
			free(input);
			input = get_next_line(0);
		}
	}
	else if (read > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
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
		outfile = open(av[ac - 1], O_CREAT | O_APPEND, 0777);
		here_doc(av[2]);
	}
	else
	{
		i = 1;
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		infile = open(av[1], O_RDONLY);
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	while (++i < ac - 2)
		child_process(av[i], env);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	exec(av[ac - 2], env);
}
