/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:32:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/08 15:42:27 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*best_node(t_list *a, t_list *b, short ascending)
{
	t_list	*pa;
	t_list	*tmp;
	int		cost_best;
	int		cost_tmp;

	pa = a;
	tmp = a->next;
	cost_best = op_cost(a, b, *(int *)a->content, ascending);
	while (tmp)
	{
		cost_tmp = op_cost(a, b, *(int *)tmp->content, ascending);
		if (ft_abs(cost_best) > ft_abs(cost_tmp))
		{
			pa = tmp;
			cost_best = cost_tmp;
		}
		tmp = tmp->next;
	}
	return (pa);
}

void	efficient_move_des(t_list **a, t_list **b, t_list *pa)
{
	int	cost_a;
	int	cost_b;
	int	common;

	cost_a = cost_to_top(*a, ft_index(*a, *(int *)pa->content));
	cost_b = cost_to_top(*b, target_pos_des(*b, *(int *)pa->content));
	common = ft_min(ft_abs(cost_a), ft_abs(cost_b));
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		while (common--)
			rotate_ab(a, cost_a, b, cost_b);
		common = ft_min(ft_abs(cost_a), ft_abs(cost_b));
		cost_a -= common * (ft_abs(cost_a) / cost_a);
		cost_b -= common * (ft_abs(cost_b) / cost_b);
	}
	while (cost_a)
	{
		rotate_a(a, cost_a);
		cost_a -= ft_abs(cost_a) / cost_a;
	}
	while (cost_b)
	{
		rotate_b(b, cost_b);
		cost_b -= ft_abs(cost_b) / cost_b;
	}
}

void	efficient_move_asc(t_list **a, t_list **b, t_list *pa)
{
	int	cost_a;
	int	cost_b;
	int	common;

	cost_a = cost_to_top(*a, ft_index(*a, *(int *)pa->content));
	cost_b = cost_to_top(*b, target_pos_asc(*b, *(int *)pa->content));
	common = ft_min(ft_abs(cost_a), ft_abs(cost_b));
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		while (common--)
			rotate_ab(a, cost_a, b, cost_b);
		common = ft_min(ft_abs(cost_a), ft_abs(cost_b));
		cost_a -= common * (ft_abs(cost_a) / cost_a);
		cost_b -= common * (ft_abs(cost_b) / cost_b);
	}
	while (cost_a)
	{
		rotate_b(a, cost_a);
		cost_a -= ft_abs(cost_a) / cost_a;
	}
	while (cost_b)
	{
		rotate_a(b, cost_b);
		cost_b -= ft_abs(cost_b) / cost_b;
	}
}

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*pa;

	while (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
	{
		pa = best_node(*a, *b, 0);
		efficient_move_des(a, b, pa);
		ft_pb(b, a);
	}
	ft_sort_three(a);
}

void	back_to_a(t_list **a, t_list **b)
{
	t_list	*pb;

	while (*b)
	{
		pb = best_node(*b, *a, 1);
		efficient_move_asc(b, a, pb);
		ft_pa(a, b);
	}
}
