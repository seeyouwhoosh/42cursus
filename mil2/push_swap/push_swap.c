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

#include <unistd.h>
#include "push_swap.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
}

void	ft_sort_three(t_list **a)
{
	int	one;
	int	two;
	int	three;

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
		;
}

void	ft_turk_alg(t_list **a, t_list **b)
{
	t_list	*pa;
	t_list	*tmp;

	pa = *a;
	tmp = (*a)->next;
	while (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
	{
		while (pa)
		{
			if (op_cost(pa, *b, *(int *)pa->content) > op_cost(pa, *b, *(int *)tmp->content))
				pa = tmp;
			tmp = tmp->next;
		}

	}
}

/* Makes moves like rotating both or rrotating both based on the node pa */
void	efficient_move(t_list **a, t_list **b, t_list *pa)
{
	int	cost_a;
	int	cost_b;
	int	common;

	cost_a = cost_to_top(a, ft_index(a, *(int *)pa));
	cost_b = cost_to_top(b, target_pos(b, *(int *)pa));
	common = ft_abs(cost_a - cost_b);
	if (cost_a > 0 && cost_b > 0)
	{
		while (common--)
			ft_rr(a, b);
		while (cost_a-- - common)
			ft_ra(a);
		while (cost_b-- - common)
			ft_rb(b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (common--)
			ft_rrr(a, b);
		while (cost_a-- - common)
			ft_rra(a);
		while (cost_b-- - common)
			ft_rrb(b);
	}
	else
	{

	}
}

void	rotate_a(t_list **a, int cost_a)
{
	if (cost_a > 0)
		ft_ra(a);
	else if (cost_a < 0)
		ft_rra(a);
}

int	pos_min_cost(t_list *a, t_list *b)
{
	t_list	*pa;
	t_list	*pb;
	int		cost;

	pa = a;
	pb = b;
	cost = op_cost(a, b, *(int *)a);
	pa = pa->next;
	while (pa)
	{
		if (cost < op_cost(a, b, *(int*)a))
		{
			cost = op_cost(a, b, *(int*)a);
			break;
		}
		pa = pa->next;
	}
	

}

int	main(int ac, char **av)
{
	int		*n;
	int		i;
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		n = malloc(sizeof(int));
		if (!n || !is_int(av[i]))
			return (ft_lstclear(&lsta, del), error_message(), 1);
		*n = ft_atoi(av[i]);
		ft_lstadd_back(&lsta, ft_lstnew(n));
		i++;
	}
	if (lstrepsint(lsta))
		return (error_message(), 1);
	ft_sort(&lsta, &lstb); lstprint(lsta, 'd'); lstprint(lstb, 'd');
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);
	return (0);
}

