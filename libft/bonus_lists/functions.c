/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:02:32 by xwu               #+#    #+#             */
/*   Updated: 2025/06/26 12:25:34 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>
#include <stdlib.h>



/* Crea un nuevo nodo utilizando malloc(3). La
variable miembro ’content’ se inicializa con el
contenido del parámetro ’content’. La variable
’next’, con NULL.*/
t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list *));
	newlist->content = malloc(sizeof(content));
	return (&newlist);
}
/* Añade el nodo ’new’ al principio de la lista ’lst’. */
void ft_lstadd_front(t_list **lst, t_list *new)
{
	;
}

#include <stdio.h>

int	main(void)
{
	void *p;

	printf("%zu; %zu; %zu", sizeof(t_list *), sizeof(t_list.content));
	return (0);
}
