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
	int		*first;
	int		*second;

	if (!a || !a->next || !a->content || !a->next->content)
		return ;
	first = a->content;
	second = a->next->content;
	a->content = second;
	a->next->content = first;
	if (!b || !b->next || !b->content || !b->next->content)
		return ;
	first = b->content;
	second = b->next->content;
	b->content = second;
	b->next->content = first;
	write(1, "ss\n", 3);
}

void	ft_rr(t_list **a, t_list **b)
{
	t_list	*start;

	if (!a || !(*a) || !(*a)->content)
		return ;
	start = *a;
	ft_lstadd_back(a, start);
	*a = (start)->next;
	start->next = NULL;
	if (!b || !(*b) || !(*b)->content)
		return ;
	start = *b;
	ft_lstadd_back(b, start);
	*b = (start)->next;
	start->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_rrr(t_list **a, t_list **b)
{
	t_list	*end;
	t_list	*ptr;

	if (!a || !(*a) || !(*a)->content || !(*a)->next)
		return ;
	ptr = *a;
	end = ft_lstlast(*a);
	while (ptr->next->next)
		ptr = ptr->next;
	ft_lstadd_front(a, end);
	ptr->next = NULL;
	if (!b || !(*b) || !(*b)->content || !(*b)->next)
		return ;
	ptr = *b;
	end = ft_lstlast(*b);
	while (ptr->next->next)
		ptr = ptr->next;
	ft_lstadd_front(b, end);
	ptr->next = NULL;
	write(1, "rrr\n", 4);
}

void	rotate_ab(t_list **a, int cost_a, t_list **b, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		ft_rr(a, b);
	else if (cost_a < 0 && cost_b < 0)
		ft_rrr(a, b);
}
