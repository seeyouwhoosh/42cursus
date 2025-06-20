/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/20 22:24:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

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

/* 
char	*ft_strndump(char **dump, char *litter, unsigned int n)
{
	char			*newstring;
	unsigned int	i;
	unsigned int	ndump;

	ndump = ft_strlen(*dump);
	if (n == 0)
		n = ft_strlen(litter);
	if (n > ft_strlen(litter))
		return (NULL);
	i = ndump + n + 1;
	newstring = malloc(i);
	if (!newstring)
		return (NULL);
	newstring[i] = '\0';
	i--;
	while (i--)
	{
		if (i >= ndump)
			newstring[i] = litter[i - ndump];
		else
			newstring[i] = (*dump)[i];
	}
	free(*dump);
	dump = &newstring;
	return (*dump);
}
 */

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (count > i)
			((char *)dest)[i] = ((const char *)src)[i++];
	}
	else if (dest > src)
		while (count--)
			((char *)dest)[count] = ((const char *)src)[count];
	return (dest);
}

// size_t ft_strpdump(char **line, char *buffer, char *newlinepos); (incluyendo el newline) if newlinepos == NULL, se copia todo, si buffer == NULL, return 0; Se añade el '\0' al final.

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
		if (!(buffer[0]))
		{
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
				return (NULL);
			buffer[bytesread] = '\0';
		}
		newlinepos = ft_strchr(buffer, '\n');
		nmoved = ft_strpdump(&line, buffer, newlinepos); 
		remaining = ft_strlen(buffer + nmoved) + 1;
		if (newlinepos)
			return (ft_memmove(buffer, newlinepos, remaining), line);
		else
			buffer[0] = '\0';
	}
}



int	main(void)
{
	char list[][100] = {"", "Hello World\n", "Esto es \n una línea nueva", " ", "\n"};

	/* TESTS DE FUNCIONES AUXILIARES */
	printf("\nft_strlen test: ");
	size_t n;
	size_t ncomp;
	for (size_t i = 0; i < 5; i++)
	{
		if ((n = ft_strlen(list[i])) != (ncomp = strlen(list[i])))
		{
			printf("Break in %ld\n", i);
			n = -1;
			break;
		}
	}
	if (n != -1)
		printf("Pass");

	printf("\nft_strchr test: ");
	char *s;
	char *scomp;
	for (size_t i = 0; i < 5; i++)
	{
		if ((s = ft_strchr(list[i], '\n')) != (scomp = ft_strchr(list[i], '\n')))
		{
			printf("Break in %ld\n", i);
			s = NULL;
			break;
		}
	}
	if (s)
		printf("Pass");

	printf("\nft_strpdump test (MANUAL)\n");
	char **lines = malloc(sizeof(char *) * 5);
	char correct_lines[][128] = {"", "Hello World\n", "Esto es \n", " ", "\n"};
	
	for (size_t i = 0; i < 5; i++)
	{
		size_t ndump = ft_strpdump(&(lines[i]), list[i], ft_strchr(list[i], '\n'));
		int ncmp = strcmp(lines[i], correct_lines[i]);
		printf("\n---\nString to dump: \"%s\"\nString dumped:\"%s\"\nCharacters dumped: %ld\nComparison return: %d\n---\n", list[i], lines[i], ndump, ncmp);
		if (ncmp)
		{
			printf("Break in %ld\n", i);
			s = NULL;
			break;
		}
	}
	for (size_t i = 0; i < 5; i++)
		free(lines[i]);
	if (s)
		printf("\nTest result: Pass");


	
	printf("\n");
	FILE *fp = fopen("text.txt", "r");
	char *gline = NULL;
	size_t m = 0;
	size_t totalnlines = 0;
	ssize_t nline = getline(&gline, &m, fp);
	while (nline > -1)
	{
		totalnlines += nline;
		nline = getline(&gline, &m, fp);
	}
	printf("Total characters read: %ld\n", totalnlines);
	free(gline);
	fclose(fp);

	int fd = open("text.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	
	return (0);
}
