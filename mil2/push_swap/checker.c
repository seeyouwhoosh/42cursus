/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/08 15:44:27 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		i;
	size_t	strlen;

	i = -1;
	while (av[++i])
	{
		strlen = ft_strlen(av[i]);

		if (!ft_strncmp(av[i], "sa", strlen))
			lstswap(*lsta);
		else if (!ft_strncmp(av[i], "pa", strlen))
			lstpush(lsta, lstb);
		else if (!ft_strncmp(av[i], "ra", strlen))
			lstrotate(lsta);
		else if (!ft_strncmp(av[i], "rra", strlen))
			lstrrotate(lsta);
		else if (!ft_strncmp(av[i], "sb", strlen))
			lstswap(*lstb);
		else if (!ft_strncmp(av[i], "pb", strlen))
			lstpush(lstb, lsta);
		else if (!ft_strncmp(av[i], "rb", strlen))
			lstrotate(lstb);
		else if (!ft_strncmp(av[i], "rrb", strlen))
			lstrrotate(lstb);
		else if (!ft_strncmp(av[i], "rr", strlen))
		{
			lstrotate(lsta);
			lstrotate(lstb);
		}
		else if (!ft_strncmp(av[i], "rrr", strlen))
		{
			lstrrotate(lstb);
			lstrrotate(lsta);
		}
		else
			return (error_message(), 0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;
	char	*steps;

	if (ac < 2)
		return (error_message(), 1);
	lsta = NULL;
	lstb = NULL;
	parsing(ac, av, &lsta);
	if (!lsta || lstrepsint(lsta))
		return (ft_lstclear(&lsta, del), error_message(), 1);

	steps = read_stdin();
	av = ft_split(steps, '\n');

	if (make_moves(av, &lsta, &lstb))
	{
		if (lstsortedsint(lsta) && lstb == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	/* DELETE */
	ft_printf("All stuff\n");
	ft_putstrstr(av, ft_strwords(steps, '\n'), ' ');
	lstprint(lsta, 'd');

	/* Demás feres*/
	ft_freesplit(av, ft_strwords(steps, '\n'));
	free(steps);
	ft_lstclear(&lsta, del);
	return (0);
}
