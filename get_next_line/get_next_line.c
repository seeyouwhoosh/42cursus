/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/14 17:31:15 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 2048

#include <stdio.h>
#include <fcntl.h>

int	ft_strchrpos(char *line, int c) /* Devuelve la posición en la que se encuentra el character c, un poco inútil, la verdad */
{
	unsigned int	i;

	i = 0;
	while (line[i]++)
		if (line[i] == c)
			return (i);
	return (-1);
}

size_t	ft_strlen(char *str)
{
	size_t	n;

	while(*str++)
		n++;
	return (n);
}



char	*ft_strndump(char **dump, char *litter, unsigned int n) /* Esta creo que es la función que más falla. Se supone que coge dos punteros y la cantidad que se tiene que copiar. Creoq ue lo má feo de este programa es que sobreescribre directamente sobre la dirección del puntero. */
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

char	*get_next_line(int fd) /* La lógica creo que debería estar bien, pero como lo he usado teniendo en cuenta las funciones anteriores, pues bueno xd. */
{
	char		*chunk;
	static char	*pile;
	char		*line;
	int			nbytes;
	int			i;

	nbytes = 1;
	pile = (char *)malloc(BUFFER_SIZE);
	chunk = (char *)malloc(BUFFER_SIZE);
	line = NULL;
	if (!chunk)
		return (NULL);
	while (nbytes > 0)
	{
		nbytes = read(fd, chunk, BUFFER_SIZE);
		if (nbytes <= 0)
			return (free(chunk), NULL);
		i = ft_strchrpos(chunk, '\n');
		if (i != -1)
		{
			ft_strndump(&line, chunk, i + 1);
			pile = &chunk[i];
			return (line);
		}
		else
			ft_strndump(&line, chunk, 0);
	}
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
	
	// Checking strndump
	char *f = "hola, safjisdaf ";
	char *s = "socorro, help";
	printf("%s", ft_strndump(&f, s, 7));
	return (0);
}

