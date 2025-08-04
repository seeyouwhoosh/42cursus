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
	ft_sort(&lsta, &lstb);
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);
	return (0);
}

/* lstprint(lsta, 'd'); lstprint(lstb, 'd'); */