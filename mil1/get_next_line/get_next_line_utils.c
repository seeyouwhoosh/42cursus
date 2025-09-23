/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/25 16:29:29 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (!str)
		return (0);
	n = 0;
	while (*str++)
		n++;
	return (n);
}

void	ft_gnl_memmove(char *dest, const char *src, size_t count)
{
	size_t	i;

	if (!src)
	{
		dest[0] = '\0';
		return ;
	}
	i = 0;
	src++;
	while (count > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ;
}

size_t	ft_strpdump(char **line, char *buffer, char *pos_nl)
{
	size_t	n;
	char	*newline;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!pos_nl)
		n = ft_strlen(buffer);
	else
		n = pos_nl - buffer + 1;
	newline = malloc(ft_strlen(*line) + n + 1);
	if (!newline)
		return (0);
	while (*line && (*line)[i])
	{
		newline[i] = (*line)[i];
		i++;
	}
	while (j++ < n)
		newline[i + j - 1] = buffer[j - 1];
	newline[i + j - 1] = '\0';
	free(*line);
	*line = newline;
	return (n);
}
