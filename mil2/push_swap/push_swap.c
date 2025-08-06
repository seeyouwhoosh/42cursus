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

t_list	*best_node(t_list *a, t_list *b)
{
	t_list	*pa;
	t_list	*tmp;
	int		cost_best;
	int		cost_tmp;

	pa = a;
	tmp = a->next;
	cost_best = op_cost(a, b, *(int *)a->content);
	while (tmp)
	{
		cost_tmp = op_cost(a, b, *(int *)tmp->content);
		if (ft_abs(cost_best) > ft_abs(cost_tmp))
		{
			pa = tmp;
			cost_best = cost_tmp;
		}
		tmp = tmp->next;
	}
	return (pa);
}

/* Makes moves like rotating both or rrotating both based on the node pa */
void	efficient_move(t_list **a, t_list **b, t_list *pa)
{
	int	cost_a;
	int	cost_b;
	int	common;

	cost_a = cost_to_top(*a, ft_index(*a, *(int *)pa->content));
	cost_b = cost_to_top(*b, target_pos(*b, *(int *)pa->content));
			common = ft_min(ft_abs(cost_a), ft_abs(cost_b));

	ft_printf("\nTarget_pos: %d\nCommon: %d \ncost_a: %d, \ncost_b: %d\n", target_pos(*b, *(int *)pa->content), common, cost_a, cost_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		while (common--)
			rotate_ab(a, cost_a, b, cost_b);
		common = ft_min(ft_abs(cost_a), ft_abs(cost_b));
		if (cost_a > 0)
			cost_a -= common;
		else if (cost_a < 0)
			cost_a += common;
		if (cost_b > 0)
			cost_b -= common;
		else if (cost_b < 0)
			cost_b += common;
	}

	while (cost_a)
	{
		rotate_a(a, cost_a);
		if (cost_a > 0)
			cost_a--;
		else
			cost_a++;
	}
	while (cost_b)
	{
		rotate_b(b, cost_b);
		if (cost_b > 0)
			cost_b--;
		else
			cost_b++;
	}
	ft_pa(b, a);
}

void	push_to_b(t_list **a, t_list **b)
{
	t_list	*pa;

	while (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
	{
		pa = best_node(*a, *b);
		efficient_move(a, b, pa);
		lstprint(*a, 'd'); lstprint(*b, 'd'); ft_printf("\n");
	}
	ft_sort_three(a);

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
	lstprint(*a, 'd'); lstprint(*b, 'd'); ft_printf("\n");

	if (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
		ft_pb(b, a); 
	lstprint(*a, 'd'); lstprint(*b, 'd'); ft_printf("\n");

	if (ft_lstsize(*a) > 3 && !lstsortedsint(*a))
		push_to_b(a, b);
	/* Back to A*/
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

