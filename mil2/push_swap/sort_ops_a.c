/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:26:49 by xwu               #+#    #+#             */
/*   Updated: 2025/07/31 13:33:31 by xwu              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/* Swap: intercambiar los primeros dos elementos de la lista */
void	ft_sa(t_list *lst)
{
	int		*first;
	int		*second;

	if (!lst || !lst->next || !lst->content || !lst->next->content)
		return ;
	first = lst->content;
	second = lst->next->content;
	lst->content = second;
	lst->next->content = first;
	write(1, "sa\n", 3);
}

/* Push: Coger el primer elemento de B y ponerlo en A (push to A)*/
void	ft_pa(t_list **a, t_list **b)
{
	t_list	*ptr;

	if (!b || !(*b))
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = NULL;
	ft_lstadd_front(a, ptr);
	write(1, "pa\n", 3);
}

/* Rotate: Rotar todos los elementos, el primero se vuelve el último */
void	ft_ra(t_list **lst)
{
	t_list	*start;

	if (!lst || !(*lst) || !(*lst)->content)
		return ;
	start = *lst;
	ft_lstadd_back(lst, start);
	*lst = (start)->next;
	start->next = NULL;
	write(1, "ra\n", 3);
}

/* Rotar todos los elementos pero al revés, el último elemento se vuelve el
primero */
void	ft_rra(t_list **lst)
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
	write(1, "rra\n", 4);
}
