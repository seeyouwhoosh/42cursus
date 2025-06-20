/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/21 00:37:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_cp;

	s_cp = (char *)s;
	if (!s_cp)
		return (NULL);
	while (*s_cp)
	{
		if (*s_cp == c)
			return(s_cp);
		s_cp++;
	}
	if (c == '\0')
		return (s_cp);
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

size_t ft_strpdump(char **line, char *buffer, char *newlinepos)
{
	char	*newline;
	char	**ogline;
	size_t	i;

	i = 0;
	ogline = line;
	if (!(*line))
		newline = malloc(ft_strlen(buffer) + 1);
	else
	{
		newline = malloc(ft_strlen(*line) + ft_strlen(buffer) + 1);
		if (!newline)
			return (0);
		while (**line)
			newline[i++] = *(*line)++;
	}
	while (buffer <= newlinepos || ((!newlinepos) && *buffer))
		newline[i++] = *buffer++;
	newline[i] = '\0';
	free(*ogline);
	*ogline = newline;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytesread;
	char		*newlinepos;
	size_t		nmoved;
	size_t		remaining;
	
	while (1)
	{
		line = NULL;
		if (buffer[0] == '\0')
		{
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
				return (NULL);
			buffer[bytesread] = '\0';
		}
		newlinepos = ft_strchr(buffer, '\n');
		nmoved = ft_strpdump(&line, buffer, newlinepos); totalnlines += nmoved; // QUITAR ESTA LÍNEA
		remaining = ft_strlen(buffer) - nmoved + 1;
		if (remaining == 1 || newlinepos)
			return (ft_gnl_memmove(buffer, newlinepos, remaining), line);
		else
			buffer[0] = '\0';
	}
}

