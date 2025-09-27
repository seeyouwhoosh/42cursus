/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/07/01 18:39:52 by xwu              ###   ########.fr       */
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
			if (fd < 0 || bytesread <= 0 || BUFFER_SIZE < 0 || !(*buffer))
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

/*
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
char	*get_next_line(int fd);
*/

/* 
int	main(void)
{
	printf("\nTEST get_next_line: \n");
	FILE	*fp = fopen("text", "r");
	char	*gline = NULL;
	size_t	m = 0;
	size_t	i = 0;
	int		fd = open("text", O_RDONLY);
	char	*gnlline = NULL;

	while (getline(&gline, &m, fp) > -1)
	
	{
		i++;
		gnlline = get_next_line(fd);
		if (strcmp(gnlline, gline))
		{
			printf("Diff in \"%s\" != \"%s\"\n", gnlline, gline);
			m = -1;
			free(gnlline);
			break ;
		}
		else
			printf("%ld:	GNL \"%s\"\n	GL  \"%s\"\n", i, gnlline, gline);
		free(gnlline);
	}
	printf("TEST read from file complete\n");

	free(gline);
	fclose(fp);
	close(fd);

	return (0);
}
/*/

#include <stdio.h>
#include <fcntl.h>
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i = 1;

	if (argc >= 2)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				perror(argv[i]);
				i++;
				continue;
			}
			printf("📂 Leyendo archivo: %s\n", argv[i]);
			while ((line = get_next_line(fd)))
			{
				printf("👉 \"%s\"\n", line);
				free(line);
			}
			close(fd);
			printf("TEST read from file complete\n");
			i++;
		}
	}
	else
	{
	printf("🔁 Leyendo desde stdin (escribe y pulsa Ctrl+D para terminar):\n");
		while ((line = get_next_line(0)))
		{
			printf("👉 \"%s\"\n", line);
			free(line);
		}
		printf("TEST read from file complete\n");
	}
	return (0);
}

