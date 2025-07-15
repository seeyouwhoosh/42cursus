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

/*
struct nombre_struct
{
	type	name;
};

declaración sería:

nombre_struct	cosa;
ptr->y = (*ptr).y

Dinamically allocated structs
*/


/* Crea un nuevo nodo utilizando malloc(3). La
variable miembro ’content’ se inicializa con el
contenido del parámetro ’content’. La variable
’next’, con NULL.*/
t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->next = NULL;
	newlist->content = content;
	return (newlist);
}

/* Añade el nodo ’new’ al principio de la lista ’lst’.*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* Cuenta el número de nodos de una lista.*/
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/* Devuelve el último nodo de la lista.*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

#include <stdio.h>

int	main(void)
{
	return (0);
}


/*
I'm pretty sure that my projects are correct. 

I need 5 points in total
I have 2.
I will gain 2 when I let Alberto correct my b2br.
I will have 4 points. 
I still need one. It would be good if I could trade it with someone. There was a guy, called Santiago, not sure if he's still here. Guess not, today was his last day before being absorbed.

I need to correct someone, but there is a problem, as people who started with the second milestone aren't going to finish so soon and people who need corrections are can't be corrected by me, as my level is too low.
*/
