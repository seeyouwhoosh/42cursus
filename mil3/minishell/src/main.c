/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:50:04 by xwu               #+#    #+#             */
/*   Updated: 2025/10/31 11:50:04 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "libft_utils.c"

int	all_whitespace(char	*s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s != 32 || (*s < 9 && *s > 13))
			return (0);
		s++;
	}
	return (1);
}

void	int_signal(int n)
{
	(void)n;
	signal(SIGINT, SIG_IGN);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	signal(SIGINT, int_signal);
}

char	*get_path(char *cmd, char **env)
{
	size_t	i;
	char	**split_paths;
	char	*pathplus;
	char	*path;

	i = -1;
	while (env[++i] && !ft_strnstr(env[i], "PATH=", 5))
		;
	split_paths = ft_split_sep(env[i] + 5, ':');
	if (!split_paths)
		return (NULL);
	i = -1;
	while (split_paths[++i])
	{
		pathplus = ft_strjoin(split_paths[i], "/");
		path = ft_strjoin(pathplus, cmd);
		free(pathplus);
		if (!access(path, X_OK))
			return (ft_freesplit(split_paths), path);
		free(path);
	}
	ft_freesplit(split_paths);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": Command not found\n", 20);
	return (NULL);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**split_cmd;

	split_cmd = ft_split(cmd);
	path = get_path(split_cmd[0], env);
	if (!path)
	{
		ft_freesplit(split_cmd);
		free(path);
		return ;
	}
	if (execve(path, split_cmd, env))
	{
		perror(path);
		ft_freesplit(split_cmd);
		free(path);
	}
}

int	process_args(char *line, char **env)
{
	char		**tokens;
	int			pid;
	t_cmdtab	cmdtab;

	tokens = ft_split(line);
	while (*tokens)
	{
		if (ft_strcmp(*tokens, "|") || ft_strcmp(*tokens, ">") || ft_strcmp(*tokens, "<"))
	}
	(void)tokens;
	pid = fork();
	if (!pid)
	{
		exec(line, env);
		exit(0);
	}
	wait(NULL);
	write(1, "Finished\n", 9);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*line;

	(void)av;
	(void)env;
	if (ac != 1)
		return(write(1, "\e[1;31mInvalid arguments\e[0m\n", 29));
	signal(SIGINT, int_signal);
	signal(SIGQUIT, SIG_IGN);
	line = (char *)1;
	while (line)
	{
		line = readline("Minishell> ");
		rl_on_new_line();
		if (all_whitespace(line))
			continue ;
		process_args(line, env);
		add_history(line);
		free(line);
	}
}