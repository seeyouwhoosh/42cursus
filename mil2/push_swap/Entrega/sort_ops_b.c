/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/08 15:26:16 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_list *lst)
{
	lstswap(lst);
	write(1, "sb\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	lstpush(a, b);
	write(1, "pb\n", 3);
}

void	ft_rb(t_list **lst)
{
	lstrotate(lst);
	write(1, "rb\n", 3);
}

void	ft_rrb(t_list **lst)
{
	lstrrotate(lst);
	write(1, "rrb\n", 4);
}

void	rotate_b(t_list **b, int cost_b)
{
	if (cost_b > 0)
		ft_rb(b);
	else if (cost_b < 0)
		ft_rrb(b);
}
