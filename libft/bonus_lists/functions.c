/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:02:32 by xwu               #+#    #+#             */
/*   Updated: 2025/07/17 17:41:02 by xwu              ###   ########.fr       */
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
		if (!newlst)
			newlst = ft_lstnew(lcontent);
		else
			ft_lstadd_back(&newlst, ltemp);
		lst = lst->content;
	}
	return (newlst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:57:49 by xwu               #+#    #+#             */
/*   Updated: 2025/07/17 17:34:44 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h" // o el archivo donde estén tus funciones

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%s] -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	del_content(void *content)
{
	free(content);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	abs_len;

	abs_len = ft_strlen(s) + 1;
	ptr = malloc(abs_len);
	if (!ptr)
		return (NULL);
	while (abs_len)
	{
		abs_len--;
		ptr[abs_len] = s[abs_len];
	}
	return (ptr);
}

void	*duplicate_content(void *content)
{
	return strdup((char *)content);
}

void	to_upper(void *content)
{
	char *str = (char *)content;
	for (int i = 0; str[i]; i++)
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
}

int	main(void)
{
	// Crear nodos
	t_list *a = ft_lstnew(strdup("uno"));
	t_list *b = ft_lstnew(strdup("dos"));
	t_list *c = ft_lstnew(strdup("tres"));

	// Conectarlos manualmente
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);

	printf("Lista original:\n");
	print_list(a);

	// Test ft_lstsize
	printf("Tamaño: %d\n", ft_lstsize(a));

	// Test ft_lstlast
	t_list *last = ft_lstlast(a);
	printf("Último nodo: %s\n", (char *)last->content);

	// Test ft_lstadd_front
	t_list *head = ft_lstnew(strdup("cero"));
	ft_lstadd_front(&a, head);
	printf("Después de añadir al frente:\n");
	print_list(a);

	// Test ft_lstiter
	ft_lstiter(a, to_upper);
	printf("Después de ft_lstiter (to_upper):\n");
	print_list(a);

	// Test ft_lstmap
	printf("Copia con ft_lstmap:\n");
	t_list *copy = ft_lstmap(a, duplicate_content, del_content);
	print_list(copy);

	// Test ft_lstdelone (elimina un nodo suelto)
	t_list *tmp = ft_lstnew(strdup("borrar"));
	printf("Nodo suelto antes de borrar: %s\n", (char *)tmp->content);
	ft_lstdelone(tmp, del_content);
	printf("Nodo suelto borrado.\n");

	// Test ft_lstclear
	ft_lstclear(&a, del_content);
	ft_lstclear(&copy, del_content);
	printf("Listas liberadas.\n");

	return 0;
}
