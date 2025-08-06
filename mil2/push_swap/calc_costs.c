/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/04/19 20:47:48 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(t_list *l, int n)
{
	t_list	*tmp;
	int		i;
	int		nb;

	i = 0;
	tmp = l;
	while (tmp)
	{
		nb = *(int *)tmp->content;
		if (n == *(int *)tmp->content)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	cost_to_top(t_list *l, int index)
{
	int	size;

	if (index == -1)
		return (0);
	size = ft_lstsize(l);
	if (index <= size / 2)
		return (index);
	else
		return (-(size - index));
}

int	target_pos(t_list *b, int n)
{
	int		i;
	t_list	*tmp;
	int		now;
	int		next;

	tmp = b;
	i = 0;

	now = *(int *)tmp->content;
	next = *(int *)tmp->next->content;
	while (tmp)
	{
		if ()
	}
	if (n > ft_maxint(b) || n < ft_minint(b))
	{
		while (*(int *)tmp->content != ft_maxint(b))
		{
			i++;
			tmp = tmp->next;
		}
	}
	else
	{
		while (*(int *)tmp->content > n)
		{
			i++;
			tmp = tmp->next;
		}
	}
	if (i <= ft_lstsize(b) / 2)
		return (i);
	else
		return (-(ft_lstsize(b) - i));
}

int	op_cost(t_list *a, t_list *b, int n)
{
	int	index_a;
	int	cost_a;
	int	target_pos_b;
	int	cost_b;

	index_a = ft_index(a, n);

	if (index_a == -1)
		return (-1);
	cost_a = cost_to_top(a, index_a);
	target_pos_b = target_pos(b, n);
	if (target_pos_b == -1)
		return (-1);
	cost_b = cost_to_top(b, target_pos_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
		return (ft_max(ft_abs(cost_a), ft_abs(cost_b)));
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}
