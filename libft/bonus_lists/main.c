/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:57:49 by xwu               #+#    #+#             */
/*   Updated: 2025/07/16 18:58:03 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h" // o el archivo donde estén tus funciones

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
	t_list *copy = ft_lstmap(a, duplicate_content, del_content);
	printf("Copia con ft_lstmap:\n");
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
