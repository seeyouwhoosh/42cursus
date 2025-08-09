/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/09 01:44:26 by xwu              ###   ########.fr       */
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
		tmp = joined;
		joined = ft_strjoin(joined, av[i]);
		free(tmp);
		tmp = joined;
		joined = ft_strjoin(joined, " ");
		free(tmp);
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
	j = -1;
	while (av[++j])
	{
		n = malloc(sizeof(int));
		if (!n || !is_int(av[j]))
			return (ft_lstclear(lsta, del), free(n));
		*n = ft_atoi(av[j]);
		ft_lstadd_back(lsta, ft_lstnew(n));
	}
	ft_freesplit(av, ft_strwords(joined, ' '));
	free(joined);
}
