/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/22 19:37:31 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
			return (s_cp);
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

/* size_t	ft_strpdump(char **line, char *buffer, char *newlinepos)
{
	char	*newline;
	char	**ogline;
	size_t	i;

	i = 0;
	ogline = line;
	if (!(*line))
	{
		newline = malloc(ft_strlen(buffer) + 1);
		printf("2.1. SIZE: %ld", ft_strlen(buffer));
		printf("2.2. P_NL: %p", newline);
	}
	else
	{
		newline = malloc(ft_strlen(*line) + ft_strlen(buffer) + 1);

		if (!newline)
			return (0);
		while (**line)
			newline[i++] = *(*line)++;
	}
	
	while (((!newlinepos) && *buffer) || (buffer != newlinepos))
		newline[i++] = *buffer++;
	
		newline[i] = '\0';
	free(*ogline);
	*ogline = newline;
	
	return (i);
} */

size_t	ft_strpdump(char **line, char *buffer, char *newlinepos)
{
	size_t	buffer_len;
	size_t	line_len;
	char	*newline;
	size_t	i;
	size_t	j;

	i = 0;
	line_len = 0;
	if (newlinepos)
		buffer_len = newlinepos - buffer; // el problema es que no pilla si es solo salto de línea
	else
		buffer_len = ft_strlen(buffer);
	if (*line)
		line_len = ft_strlen(*line);
	newline = malloc(buffer_len + line_len + 1);
	if (!newline)
		return (0);
	if (*line)
		while ((*line)[i++])
			newline[i - 1] = (*line)[i - 1];
	j = 0;
	while (j < (buffer_len - line_len))
		newline[i++] = buffer[j++];
	newline[i - 1] = '\0';
	free(*line);
	*line = newline;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytesread;
	char		*newlinepos;
	size_t		nmoved;

	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
				return (NULL);
			buffer[bytesread] = '\0';
			printf("1. BUFFER: \"%s\"\n", buffer);
		}
		newlinepos = ft_strchr(buffer, '\n');
		printf("2. POS_NL: \"%p\"\n", newlinepos);
		nmoved = ft_strpdump(&line, buffer, newlinepos);
		printf("3. LINE: %s\nBYTES: %ld\n", line, nmoved);
		totalnlines += nmoved; // QUITAR ESTA LÍNEA
		
		if (ft_strlen(buffer) == nmoved)
		{
			buffer[0] = '\0';
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
				return (line);
		}
		else
			ft_gnl_memmove(buffer, newlinepos, ft_strlen(buffer) - nmoved + 1);
	}
}

