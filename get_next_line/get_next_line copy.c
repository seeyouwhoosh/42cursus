/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/19 18:41:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048

#include <stdio.h>
#include <fcntl.h>

int	ft_strchrpos(char *line, int c)
{
	unsigned int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (-1);
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

char	*get_next_line(int fd)
{
	char		*chunk;
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			nbytes;
	int			i;

	nbytes = 1;
	chunk = (char *)malloc(BUFFER_SIZE);
	line = NULL;
	if (!chunk)
		return (NULL);
	if (!(buffer))
	{
		; 
	}
	while (nbytes > 0)
	{
		nbytes = read(fd, chunk, BUFFER_SIZE);
		if (nbytes <= 0)
			return (free(chunk), NULL);
		i = ft_strchrpos(chunk, '\n');
		if (i != -1)
		{
			ft_strndump(&line, chunk, i + 1);
			buffer = &chunk[i]; //memvmove)
			return (line);
		}
		else
			ft_strndump(&line, chunk, 0);
	}
	return (line);
}
 */

int	main(void)
{
	char list[][100] = {"", "Hello\n", "esto es \n una frase", " ", "\n"};
	int nlist[] = {0, 6, 19, 1, 1};
	int nllist[] = {-1, 5, 8, -1, 0};
	int n;

	printf("\nft_strlen test\n");
	for (size_t i = 0; i < 5; i++)
	{
		n = (int)ft_strlen(list[i]);
		printf("\"%s\": %d == %d?. %s\n", list[i],
			n , nlist[i],
			(n == nlist[i]) ? "Pass": "Break");
	}
	
	printf("\nft_strchrpos test\n");
	for (size_t i = 0; i < 5; i++)
	{
		n = ft_strchrpos(list[i], '\n');
		printf("\"%s\": %d == %d?. %s\n", list[i],
			n , nllist[i],
			(n == nllist[i]) ? "Pass": "Break");
	}
	return (0);
}
