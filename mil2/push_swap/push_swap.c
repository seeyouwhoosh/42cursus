/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:26:27 by xwu               #+#    #+#             */
/*   Updated: 2025/07/31 13:58:05 by xwu              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

int	ft_index(t_list *l, int n)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = l;
	while (tmp)
	{
		if (n == *(int *)tmp->content)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	cost_to_top(t_list *l, int index)
{
	int	size;

	size = ft_lstsize(l);
	if (index <= size / 2)
		return (index);
	else
		return (-(size - index));
}

int	target_pos(t_list *b, int n)
{
	int		i;
	t_list	*tmp;
	int		size;

	size = ft_lstsize(b);
	tmp = b;
	i = 0;
	while (tmp)
	{
		if (n < *(int *)tmp->content && n < *(int *)ft_lstlast(b)->content)
		{

		}
		i++;
		tmp = tmp->next;
	}
	if (i <= size / 2)
		return (i);
	else
		return (-(size - i));
}

int	op_cost(t_list *a, t_list *b, int n)
{
	int	index_a;
	int	cost_a;
	int	target_pos_b;
	int	cost_b;

	index_a = ft_index(a, n);
	if (index_a == -1)
		return (-1);
	cost_a = cost_to_top(a, index_a);
	target_pos_b = target_pos(b, n);
	if (target_pos_b == -1)
		return (-1);
	cost_b = cost_to_top(b, target_pos_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
		return (ft_max(ft_abs(cost_a), ft_abs(cost_b)));
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
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
		;// turk_algorithm
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

