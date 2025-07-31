/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:33:13 by xwu               #+#    #+#             */
/*   Updated: 2025/07/31 13:47:45 by xwu              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include "push_swap.h"

void	test_op(t_list *lsta, t_list *lstb)
{
	ft_printf("Original lists:");
	ft_printf("\n	a: "), lstprint(lsta, 'd'),ft_printf("\n	b: "),lstprint(lstb, 'd');
	ft_printf("\nSwap a:");
	ft_sa(lsta);
	ft_printf("\n	a: "), lstprint(lsta, 'd'),ft_printf("\n	b: "),lstprint(lstb, 'd');
	ft_printf("\nPush to a:");
	ft_pa(&lstb, &lsta);
	ft_printf("\n	a: "), lstprint(lsta, 'd'),ft_printf("\n	b: "),lstprint(lstb, 'd');
	ft_printf("\nRotate:");
	ft_ra(&lsta);
	ft_printf("\n	a: "), lstprint(lsta, 'd'),ft_printf("\n	b: "),lstprint(lstb, 'd');
	ft_printf("\nReverse rotate:");
	ft_rra(&lsta);
	ft_printf("\n	a: "), lstprint(lsta, 'd'),ft_printf("\n	b: "),lstprint(lstb, 'd');
	ft_printf("\n\nIs a sorted? %d\n", lstsortedsint(lsta));
}

void	error_message(void)
{
	write(2, "Error\n", 6);
}

int	main(int ac, char **av)
{
	int		*n;
	int		i;
	t_list	*lsta;
	t_list	*lstb;
	t_list	*new;

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

	/* Printing lists*/
	test_op(lsta, lstb);

	/* Frees */
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);

	return (0);
}
