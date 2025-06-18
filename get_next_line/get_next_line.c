/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/18 19:45:18 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048

#include <stdio.h>
#include <fcntl.h>

int	ft_strchr(char *line, int c)
{
	while (*line++)
		if (*line == c)
			return (1);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (0);
	while (*str++)
		n++;
	return (n);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*dump;
	char		*line;
	int			nbytes;

	int			i;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	nbytes = 1;
	if (buffer)
		line = ft_strndup(buffer, ft_strlen(buffer));
	while (nbytes > 0 && !ft_strchr(buffer, '\n'))
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes <= 0)
			break;
		buffer[nbytes] = '\0';
		dump = ft_strjoin(line, buffer);
	}
	line = ft_extractline(dump, buffer);
	return (line);
}

int	main(void)
{
	char	*filename = "text.txt";
	int	fp = open(filename, O_RDONLY);
	char *line = get_next_line(fp);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fp);
	}
	close(fp);
	printf("EOF");

	return (0);
}

