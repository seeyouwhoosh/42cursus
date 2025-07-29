/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:26:27 by xwu               #+#    #+#             */
/*   Updated: 2025/07/27 12:16:43 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_math.h"
#include "ft_lists.h"

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
		new = ft_lstnew(n);
		ft_lstadd_back(&lsta, new);
		i++;
	}
	if (lstrepsint(lsta))
		return (error_message(), 1);

	/* Printing lists*/
	ft_printf("\na: "), lstprint(lsta, 'd'),ft_printf("\nb: "),lstprint(lstb, 'd');
	lstswap(lsta);
	ft_printf("\n\na: "), lstprint(lsta, 'd'),ft_printf("\nb: "),lstprint(lstb, 'd');
	lstpush(&lstb, &lsta);
	ft_printf("\n\na: "), lstprint(lsta, 'd'),ft_printf("\nb: "),lstprint(lstb, 'd');
	lstrotate(&lsta);
	ft_printf("\n\na: "), lstprint(lsta, 'd'),ft_printf("\nb: "),lstprint(lstb, 'd');
	lstrrotate(&lsta);
	ft_printf("\n\na: "), lstprint(lsta, 'd'),ft_printf("\nb: "),lstprint(lstb, 'd');

	ft_printf("\n\nIs it sorted? %d\n", lstsortedsint(lsta));

	/* Frees */
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);

	return (0);
}
