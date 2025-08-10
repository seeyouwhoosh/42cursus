/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/10 01:28:57 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **a)
{
	int	one;
	int	two;
	int	three;

	if (ft_lstsize(*a) != 3)
		return ;
	one = *(int *)((*a)->content);
	two = *(int *)((*a)->next->content);
	three = *(int *)((*a)->next->next->content);
	if (one > two && two > three && one > three)
	{
		ft_sa(*a);
		ft_rra(a);
	}
	else if (one > two && two < three && one > three)
		ft_ra(a);
	else if (one > two && two < three && one < three)
		ft_sa(*a);
	else if (one < two && two > three && one > three)
		ft_rra(a);
	else if (one < two && two > three && one < three)
	{
		ft_rra(a);
		ft_sa(*a);
	}
}

void	ft_sort(t_list **a, t_list **b)
{
	if (lstsortedsint(*a))
		return ;
	if (ft_lstsize(*a) == 2)
		return (ft_sa(*a));
	else if (ft_lstsize(*a) == 3)
		return (ft_sort_three(a));
	if (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
		ft_pb(b, a);
	if (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
		ft_pb(b, a);
	if (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
		push_to_b(a, b);
	ft_sort_three(a);
	back_to_a(a, b);
	while (!lstsortedsint(*a))
		rotate_a(a, cost_to_top(*a, ft_index(*a, ft_minint(*a))));
}

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	if (ac < 2)
		return (0);
	parsing(ac, av, &lsta);
	if (!lsta)
		return (error_message(), 1);
	ft_sort(&lsta, &lstb);
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);
	return (0);
}
