/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/10 00:06:55 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(t_list *l, int n)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = l;
	while (tmp)
	{
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

int	target_pos_asc(t_list *b, int n)
{
	int		i;
	t_list	*tmp;

	tmp = b;
	i = 0;
	if (n < ft_minint(b) || n > ft_maxint(b))
		return (ft_index(b, ft_minint(b)));
	else
	{
		while (tmp && tmp->next)
		{
			if (*(int *)tmp->content < n && *(int *)tmp->next->content > n)
				return (i + 1);
			i++;
			tmp = tmp->next;
		}
		if (tmp && *(int *)tmp->content < n && *(int *)b->content > n)
			return (0);
	}
	return (i);
}

int	target_pos_des(t_list *b, int n)
{
	int		i;
	t_list	*tmp;

	tmp = b;
	i = 0;
	if (n > ft_maxint(b) || n < ft_minint(b))
		return (ft_index(b, ft_maxint(b)));
	else
	{
		while (tmp && tmp->next)
		{
			if (*(int *)tmp->content > n && *(int *)tmp->next->content < n)
				return (i + 1);
			i++;
			tmp = tmp->next;
		}
		if (tmp && *(int *)tmp->content > n && *(int *)b->content < n)
			return (0);
	}
	return (i);
}

int	op_cost(t_list *a, t_list *b, int n, short ascending)
{
	int	index_a;
	int	cost_a;
	int	target_pos_b;
	int	cost_b;

	index_a = ft_index(a, n);
	if (index_a == -1)
		return (-1);
	cost_a = cost_to_top(a, index_a);
	if (ascending)
		target_pos_b = target_pos_asc(b, n);
	else
		target_pos_b = target_pos_des(b, n);
	if (target_pos_b == -1)
		return (-1);
	cost_b = cost_to_top(b, target_pos_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
		return (ft_max(ft_abs(cost_a), ft_abs(cost_b)));
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}
