/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:48:13 by xwu               #+#    #+#             */
/*   Updated: 2025/07/27 11:52:00 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_lstprint(t_list *lst, char format)
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
