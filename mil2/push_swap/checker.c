/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/10 02:32:22 by xwu              ###   ########.fr       */
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
		tmp = steps;
		steps = ft_strjoin(steps, line);
		free(tmp);
		n_read = read(0, line, BUFFER_SIZE);
	}
	free(line);
	return (steps);
}

void	rotate_both(t_list **lsta, t_list **lstb, short reverse)
{
	if (reverse)
	{
		lstrrotate(lstb);
		lstrrotate(lsta);
	}
	else
	{
		lstrotate(lstb);
		lstrotate(lsta);
	}
}

int	execute_move(char *move, t_list **lsta, t_list **lstb)
{
	size_t	len;

	len = ft_strlen(move);
	if (len == 0)
		return (0);
	if (!ft_strncmp(move, "sa", len))
		lstswap(*lsta);
	else if (!ft_strncmp(move, "pa", len))
		lstpush(lsta, lstb);
	else if (!ft_strncmp(move, "ra", len))
		lstrotate(lsta);
	else if (!ft_strncmp(move, "rra", len))
		lstrrotate(lsta);
	else if (!ft_strncmp(move, "sb", len))
		lstswap(*lstb);
	else if (!ft_strncmp(move, "pb", len))
		lstpush(lstb, lsta);
	else if (!ft_strncmp(move, "rb", len))
		lstrotate(lstb);
	else if (!ft_strncmp(move, "rrb", len))
		lstrrotate(lstb);
	else if (!ft_strncmp(move, "rr", len))
		rotate_both(lsta, lstb, 0);
	else if (!ft_strncmp(move, "rrr", len))
		rotate_both(lsta, lstb, 1);
	else
		return (0);
	return (1);
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
	else
		error_message();
	return (ft_freesplit(av, ft_strwords(steps, '\n')), \
ft_lstclear(&lsta, del), free(steps), 0);
}
