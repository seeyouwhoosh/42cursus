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

void	ft_sort(t_list *a, t_list *b)
{
	if (lstsortedsint(a))
		return ;
	
}

void	ft_sort_three(t_list *a)
{
	;
}

int	op_cost(t_list *a, t_list *b)
{
	; /* Creo que para esto se va a necesitar un archivo entero... */
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
	/* push_swap sort function insert here */
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);
	return (0);
}

