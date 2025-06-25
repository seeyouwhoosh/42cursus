/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/25 16:32:06 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytesread;
	char		*pos_nl;
	size_t		n;

	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
				return (line);
			buffer[bytesread] = '\0';
		}
		pos_nl = ft_pos_nl(buffer);
		ft_strpdump(&line, buffer, pos_nl);
		n = ft_strlen(buffer) - (pos_nl - buffer) + 1;
		ft_gnl_memmove(buffer, pos_nl, n);
		if (ft_pos_nl(line))
			return (line);
	}
}
