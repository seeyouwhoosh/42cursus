/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/11 19:23:21 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048

char	*get_next_line(int fd)
{
	char	*line;
	int		nbytes;

	line = (char *) malloc(4096);
	if (!line)
		return (NULL);
	if (nbytes <= 0)
	{
		free(line);
		return (NULL);
	}
	nbytes = read(fd, line, 4096);
	line[nbytes] = '\0';
	return (line);
}



#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*filename = "text.txt";
	int	fp = open(filename, O_RDONLY);
	char *line = malloc(4096);

	line = get_next_line(fp);
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