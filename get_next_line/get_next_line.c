/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/12 18:53:34 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048

int	ft_strchrpos(char *line, int c)
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

#include <stdio.h>

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
	static char	*pile;
	char		*line;
	int			nbytes;
	int			i;

	chunk = (char *)malloc(BUFFER_SIZE);
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
			ft_strndump(&pile, &chunk[i], 0);
			return (line);
		}
		else
			ft_strndump(&line, chunk, 0);
	}
	return (line);
}

/*
1. ¿Es un buffer vacío ó no válido? GG.
2. Leer bloques de texto (according to BUFFER_SIZE).
3. Flujo:
	Si no hay salto de línea (sdl): extraer texto a line, proseguir.
	Si hay sdl en el bloque: extraer texto antes de sdl a line, extraer texto después de sdl a una pila temporal, devolver.
4. NOTA: el static variable sería la pila temporal.
5. Update: creo que vamos a necesitar 3 punteros para cavar.
*/

#include <fcntl.h>
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
	char *f = "hola, safjisdaf ";
	char *s = "socorro, help";
	printf("%s", ft_strndump(&f, s, 7));
	return (0);
}

