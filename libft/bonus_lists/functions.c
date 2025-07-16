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

#include "libft.h"
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

/* Añade el nodo ’new’ al final de la lista ’lst’.*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}

/* Toma como parámetro un nodo ’lst’ y libera la memoria del contenido utilizando la función ’del’ dada como parámetro, además de liberar el nodo. La memoria de ’next’ no debe liberarse.*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst | !del)
		return ;
	del(lst->content);
	free(lst);
}
/* Elimina y libera el nodo ’lst’ dado y todos los consecutivos de ese nodo, utilizando la función ’del’ y free(3). Al final, el puntero a la lista debe ser NULL*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!lst || !del)
		return ;

	while (*lst)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}
/* Itera la lista ’lst’ y aplica la función ’f’ en el contenido de cada nodo.*/
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

/* Itera la lista ’lst’ y aplica la función ’f’ al contenido de cada nodo. Crea una lista resultante de la aplicación correcta y sucesiva de la función ’f’ sobre cada nodo. La función ’del’ se utiliza para eliminar el contenido de un nodo, si hace falta.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*ltemp;
	void	*lcontent;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		lcontent = f(lst->content);
		ltemp = ft_lstnew(lcontent);
		if (!ltemp)
		{
			del(lcontent);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, ltemp);
		lst = lst->content;
	}
	return (newlst);
}

/*
I'm pretty sure that my projects are correct. 

I need 5 points in total
I have 2.
I will gain 2 when I let Alberto correct my b2br.
I will have 4 points. 
I still need one. It would be good if I could trade it with someone. There was a guy, called Santiago, not sure if he's still here. Guess not, today was his last day before being absorbed.

I need to correct someone, but there is a problem, as people who started with the second milestone aren't going to finish so soon and people who need corrections are can't be corrected by me, as my level is too low.

I can only remain expectant until... well, I guess I will have to ask in Slack (?)

Another problem is that people just ask whoever they already know.
*/
