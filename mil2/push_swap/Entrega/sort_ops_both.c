/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops_both.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/08 15:26:17 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_list *a, t_list *b)
{
	lstswap(a);
	lstswap(b);
	write(1, "ss\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	lstrotate(a);
	lstrotate(b);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_list **a, t_list **b)
{
	lstrrotate(a);
	lstrrotate(b);
	write(1, "rrr\n", 4);
}

void	rotate_ab(t_list **a, int cost_a, t_list **b, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		ft_rr(a, b);
	else if (cost_a < 0 && cost_b < 0)
		ft_rrr(a, b);
}
