/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/10 02:32:22 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *line)
{
	if (!ft_strcmp(line, "sa\n") || !ft_strcmp(line, "sb\n"))
		return (1);
	else if (!ft_strcmp(line, "pa\n") || !ft_strcmp(line, "pb\n"))
		return (1);
	else if (!ft_strcmp(line, "ra\n") || !ft_strcmp(line, "rb\n"))
		return (1);
	else if (!ft_strcmp(line, "rr\n") || !ft_strcmp(line, "rra\n"))
		return (1);
	else if (!ft_strcmp(line, "rrb\n") || !ft_strcmp(line, "rrr\n"))
		return (1);
	else if (!ft_strcmp(line, "ss\n"))
		return (1);
	else
		return (0);
}

char	*read_stdin(void)
{
	char	*line;
	char	*steps;
	int		n_read;
	char	*tmp;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	steps = ft_strdup("");
	n_read = read(0, line, BUFFER_SIZE);
	while (n_read > 0)
	{
		line[n_read] = '\0';
		splits = ft_split(line, '\n');
		while (*splits++)
		{
			*splits = ft_strjoin(*splits, "\n")
			if (!is_valid(*splits))
				return (free(line), free(steps), NULL);
		}
		tmp = steps;
		steps = ft_strjoin(steps, line);
		free(tmp);
		n_read = read(0, line, BUFFER_SIZE);
	}
	free(line);
	return (steps);
}
int	make_moves(char **av, t_list **lsta, t_list **lstb)
{
	int	i;

	i = -1;
	while (av[++i])
		if (!execute_move(av[i], lsta, lstb))
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;
	char	*steps;

	if (ac < 2)
		return (0);
	lsta = NULL;
	lstb = NULL;
	parsing(ac, av, &lsta);
	if (!lsta)
		return (error_message(), 1);
	steps = read_stdin();
	av = ft_split(steps, '\n');
	if (make_moves(av, &lsta, &lstb))
	{
		if (lstsortedsint(lsta) && lstb == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		error_message();
	return (ft_freesplit(av, ft_strwords(steps, '\n')), \
ft_lstclear(&lsta, del), free(steps), 0);
}
