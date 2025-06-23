/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/23 12:02:21 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_pos_nl(const char *s)
{
	char	*s_cp;

	s_cp = (char *)s;
	if (!s_cp)
		return (NULL);
	while (*s_cp)
	{
		if (*s_cp == '\n')
			return (s_cp);
		s_cp++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

void	*ft_gnl_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (!src)
	{
		((char *)dest)[0] = '\0';
		return (NULL);
	}
	i = 0;
	src++;
	while (count > i)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	((char *)dest)[i] = '\0';
	return (dest);
}

size_t	ft_strpdump(char **line, char *buffer, char *pos_nl)
{
	size_t	n;
	size_t	n;
	char	*newline;

	if (!buffer)
		return (0);
	if (!pos_nl)
		n = strlen(buffer);
	else
		n = pos_nl - buffer + 1;
	if (*line)
		newline = malloc(strlen(*line) + n + 1);
	else
		newline = malloc(n + 1);
	newline[0] = '\0';
	if (*line)
		newline = strcpy(newline, *line);
	newline = strncat(newline, buffer, n);
	free(*line);
	*line = newline;
	return (n);
}

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ret;
	return ret;
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ret;
	return ret;
}