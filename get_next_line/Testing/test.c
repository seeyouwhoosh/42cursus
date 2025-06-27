/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:56:13 by marvin            #+#    #+#             */
/*   Updated: 2025/06/20 23:56:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE // Te animo a cambiar esto también xd
# define BUFFER_SIZE 1
#endif


// Comando a ejecutar: clear && cc -Wall -Werror -Wextra test.c && ./a.out

char	*get_next_line(int fd);

int	main(void)
{
	printf("\nTEST get_next_line: \n");
	FILE	*fp = fopen("text.txt", "r");
	char	*gline = NULL;
	size_t	m = 0;
	size_t	i = 0;
	int		fd = open("text.txt", O_RDONLY);
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
			printf("%ld:\nGNL \"%s\"\nGL \"%s\"\n", i, gnlline, gline);
		free(gnlline);
	}
	printf("TEST read from file complete\n");

	free(gline);
	fclose(fp);
	close(fd);

	//system("valgrind --tool=memcheck  --leak-check=full -v ./a.out");
	return (0);
}

/*-------------------- Funciones --------------------*/

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
