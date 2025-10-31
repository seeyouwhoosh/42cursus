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
	while(*s)
	{
		if (*s != 32 || (*s < 9 && *s > 13))
			return (0);
		s++;
	}
	return (1);
}

int	main()
{
	char	*line;
	char	*name;

	name ="\e[1m\e[38;5;198mM\e[38;5;202mi\e[38;5;214mn\e[38;5;226mi\e[38;5;154m\
s\e[38;5;76mh\e[38;5;44me\e[38;5;33ml\e[38;5;21ml\e[38;5;92m> \e[0;0m";
	while ((line = readline(name)))
	{
		if (all_whitespace(line))
			continue ;
		add_history(line);
	} 
}