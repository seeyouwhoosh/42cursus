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

void	error_message(void)
{
	write(2, "Error\n", 6);
}
int		ft_lstrepsint(t_list *lst)
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
int		ft_lstsortedsint(t_list *lst)
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
	if (ft_lstrepsint(lsta))
		return (error_message(), 1);
		
	/* Printing lists*/
	ft_printf("a: ");
	ft_lstprint(lsta, 'd');
	ft_printf("\nb: ");
	ft_lstprint(lstb, 'd');
	ft_printf("\nIs it sorted? %d\n", ft_lstsortedsint(lsta));

	/* Frees */
	ft_lstclear(&lsta, del);

	return (0);
}
