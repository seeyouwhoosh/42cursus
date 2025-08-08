/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/09 01:44:26 by xwu              ###   ########.fr       */
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

int	main2(int ac, char **av)
{
	int		*n;
	int		i;
	t_list	*lsta;
	t_list	*lstb;

	lsta = NULL;
	lstb = NULL;
	i = 0;
	if (ac < 2)
		return (0);
	parsing(ac, av, lsta);
	if (lstrepsint(lsta))
		return (ft_lstclear(&lsta, del), error_message(), 1);
	ft_sort(&lsta, &lstb);
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);
	return (0);
}

void	parsing(int ac, char **av, t_list *lsta)
{
	char	*joined;
	int		i;
	char	*tmp;
	int		*n;

	joined = ft_strdup("");
	i = 0;
	while (++i < ac)
	{
		tmp = joined;
		joined = ft_strjoin(joined, av[i]);
		joined = ft_strjoin(joined, " ");
		free(tmp);
	}
	av = ft_split(joined, ' ');
	free(joined);
	while (av[i])
	{
		n = malloc(sizeof(int));
		if (!n || !is_int(av[i]))
			return (ft_lstclear(&lsta, del), error_message(), 1);
		*n = ft_atoi(av[i]);
		ft_lstadd_back(&lsta, ft_lstnew(n));
		i++;
	}
}



#include <stdlib.h>
#include <string.h>


int	main(int ac, char **av)
{
	t_list	*lsta = NULL;
	t_list	*lstb = NULL;
	char	**args;
	int		i = 0;
	int		*n;

	if (ac < 2)
		return (1);

	// Unir todos los argumentos y luego hacer split
	char *joined = ft_strdup("");
	for (int j = 1; j < ac; j++)
	{
		char *tmp = joined;
		joined = strjoin_and_free(joined, " ");
		joined = strjoin_and_free(joined, av[j]);
		free(tmp);
	}
	args = ft_split(joined, ' ');
	free(joined);

	while (args[i])
	{
		if (!is_int(args[i]))
			return (ft_lstclear(&lsta, del), free_split(args), error_message(), 1);
		n = malloc(sizeof(int));
		if (!n)
			return (ft_lstclear(&lsta, del), free_split(args), error_message(), 1);
		*n = ft_atoi(args[i]);
		ft_lstadd_back(&lsta, ft_lstnew(n));
		i++;
	}

	free_split(args);

	if (lstrepsint(lsta))
		return (ft_lstclear(&lsta, del), error_message(), 1);

	ft_sort(&lsta, &lstb);
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);
	return (0);

}

