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

void	ft_sb(t_list *lst)
{
	int		*first;
	int		*second;

	if (!lst || !lst->next || !lst->content || !lst->next->content)
		return ;
	first = lst->content;
	second = lst->next->content;
	lst->content = second;
	lst->next->content = first;
	write(1, "sb\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*ptr;

	if (!b || !(*b))
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = NULL;
	ft_lstadd_front(a, ptr);
	write(1, "pb\n", 3);
}

void	ft_rb(t_list **lst)
{
	t_list	*start;

	if (!lst || !(*lst) || !(*lst)->content)
		return ;
	start = *lst;
	ft_lstadd_back(lst, start);
	*lst = (start)->next;
	start->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rrb(t_list **lst)
{
	t_list	*end;
	t_list	*ptr;

	if (!lst || !(*lst) || !(*lst)->content || !(*lst)->next)
		return ;
	ptr = *lst;
	end = ft_lstlast(*lst);
	while (ptr->next->next)
		ptr = ptr->next;
	ft_lstadd_front(lst, end);
	ptr->next = NULL;
	write(1, "rrb\n", 3);
}
