/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:23:07 by xwu               #+#    #+#             */
/*   Updated: 2025/04/07 18:48:50 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Tasks to complete [General]
 * Learn how to make a Makefile (No debe hacer relink... qué es relink?
 * 	-Wall -Werror -Wextra
 * 	Contiene las normas $(NAME), all, clean, fclean y re
 * What is the command `ar`?
 * Why is the termination of the program *.a? 
*/

// List of functions from libc  to make
// isalpha
// isdigit
// isalnum
// isascii
// isprint
// strlen
// memset
// bzero
// memcpy
// memmove
// strlcpy
// strlcat
//  toupper
// tolower
// strchr
// strrchr
// strncmp
// memchr
// memcmp
// strnstr
// atoi

// special ones that require malloc():
// calloc
// strdup

// functions that are not literally from libc
// Look at the pdf

char *ft_substr(char const *s, unsigned int start, size_t len) // Reserva y devuelve una substring de la string s, que empieza en el índice start y tiene una longitud máxima len
{
	char substr[len + 1]; // El 1 es del '\0'
	int i;

	i = 0;	
	while (len > i)
	{
		s[start + i] = substr[i];
		i++;
	}
	return *substr;
}

