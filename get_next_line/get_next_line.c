/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/23 10:14:50 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"

char	*ft_pos_nl(const char *s)
{
	char	*s_cp;

	s_cp = (char *)s;
	if (!s_cp)
		return (NULL);
	printf("Checkpoint");
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
		}
		newlinepos = ft_strchr(buffer, '\n');
		nmoved = ft_strpdump(&line, buffer, newlinepos);
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

