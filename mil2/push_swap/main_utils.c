/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/10 01:57:10 by xwu              ###   ########.fr       */
/*   Updated: 2025/08/10 01:57:10 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
}

char	*joined_args(int ac, char **av)
{
	char	*joined;
	int		i;
	char	*tmp;

	joined = ft_strdup("");
	i = 0;
	while (++i < ac)
	{
		if (av[i][0])
		{
			tmp = joined;
			joined = ft_strjoin(joined, av[i]);
			free(tmp);
			tmp = joined;
			joined = ft_strjoin(joined, " ");
			free(tmp);
		}
	}
	return (joined);
}

void	parsing(int ac, char **av, t_list **lsta)
{
	int		*n;
	int		j;
	char	*joined;

	joined = joined_args(ac, av);
	av = ft_split(joined, ' ');
	if (!av[0])
		return (ft_freesplit(av, 0), free(joined));
	j = -1;
	while (av[++j])
	{
		if (!is_int(av[j]))
			break ;
		if (!is_int(av[j]))
			break ;
		n = malloc(sizeof(int));
		if (!n)
			break ;
		if (!n)
			break ;
		*n = ft_atoi(av[j]);
		ft_lstadd_back(lsta, ft_lstnew(n));
	}
	if (av[j] || (lstrepsint(*lsta) && *lsta))
		ft_lstclear(lsta, del);
	if (av[j] || (lstrepsint(*lsta) && *lsta))
		ft_lstclear(lsta, del);
	ft_freesplit(av, ft_strwords(joined, ' '));
	free(joined);
}
