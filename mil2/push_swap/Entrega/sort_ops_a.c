/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/08 15:26:15 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *lst)
{
	lstswap(lst);
	write(1, "sa\n", 3);
}

void	ft_pa(t_list **a, t_list **b)
{
	lstpush(a, b);
	write(1, "pa\n", 3);
}

void	ft_ra(t_list **lst)
{
	lstrotate(lst);
	write(1, "ra\n", 3);
}

void	ft_rra(t_list **lst)
{
	lstrrotate(lst);
	write(1, "rra\n", 4);
}

void	rotate_a(t_list **a, int cost_a)
{
	if (cost_a > 0)
		ft_ra(a);
	else if (cost_a < 0)
		ft_rra(a);
}
