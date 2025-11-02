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
		add_history(line);
		free(line);
	}
}