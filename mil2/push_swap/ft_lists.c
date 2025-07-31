/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:57:07 by xwu               #+#    #+#             */
/*   Updated: 2025/07/31 12:55:12 by xwu              ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	lstrepsint(t_list *lst)
{
	int		n;
	t_list	*marker;

	marker = lst->next;

	while (marker)
	{
		n = *(int *)(lst->content);
		lst = lst->next;
		while (lst)
		{
			if (n == *(int *)lst->content)
				return (1);
			lst = lst->next;
		}
		lst = marker;
		marker = marker->next;
	}
	return (0);
}

int	lstsortedsint(t_list *lst)
{
	int		n;
	t_list	*marker;

	marker = lst->next;

	while (marker)
	{
		n = *(int *)(lst->content);
		lst = lst->next;
		while (lst)
		{
			if (n > *(int *)lst->content)
				return (0);
			lst = lst->next;
		}
		lst = marker;
		marker = marker->next;
	}
	return (1);
}

void	lstprint(t_list *lst, char format)
{
	short	comma;

	comma = 0;
	ft_printf("[");
	while (lst)
	{
		if (comma)
			ft_printf(", ");
		if (format == 'd')
			ft_printf("%d", *(int *)(lst->content));
		else if (format == 'c')
			ft_printf("\'%c\'", *(char *)(lst->content));
		else if (format == 's')
			ft_printf("\"%s\"", *(char *)(lst->content));
		else if (format == 'f')
			ft_printf("%f", *(float *)(lst->content));
		else if (format == 'x')
			ft_printf("%x", *(float *)(lst->content));
		else if (format == 'u')
			ft_printf("%u", *(float *)(lst->content));
		lst = lst->next;
		comma = 1;
	}
	ft_printf("]");
}
