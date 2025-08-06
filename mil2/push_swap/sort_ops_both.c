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

void	ft_ss(t_list *a, t_list *b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a);
	ft_rb(b);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rrb(b);
}

void	rotate_ab(t_list **a, int cost_a, t_list **b, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		ft_rr(a, b);
	else if (cost_a < 0)
		ft_rr(a, b);
}
