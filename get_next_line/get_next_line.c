/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiyu <xiyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/12 00:42:08 by xiyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048

int	ft_strchrpos(char *line, int c) // No sé si esto tiene algún sentido, pero yo creo que sí
{
	unsigned int	i;

	i = 0;
	while(line[i]++)
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

void	ft_strndump(char **dump, char *litter) // Brainrot. 
{
	char 			*newstring;
	unsigned int	r;
	unsigned int	ndump;
	unsigned int	nlitter;
	
	ndump = ft_strlen(*dump);
	nlitter = ft_strlen(litter);
	r = ndump + nlitter + 1;
	newstring = malloc(r);
	if (!newstring)
		return (NULL);
	newstring[r] = '\0';
	while (--r)
	{
		if (r > ndump)
			newstring[r] = litter[r - ndump];
		else
			newstring[r] = (*dump)[r];
	}
	free(*dump);
	*dump = newstring;
}

char	*get_next_line(int fd)
{
	char		*readline;
	static char	*pile;
	int			nbytes;
	
	nbytes = 0;
	readline = (char *) malloc(BUFFER_SIZE + 1);
	if (!readline)
		return (NULL);
	nbytes = read(fd, readline, BUFFER_SIZE);
	if (nbytes <= 0)
	{
		free(readline);
		return (NULL);
	}
	if (ft_strchr(readline) != -1)
	{
		ft_strdump(&pile, readline);
		readline[nbytes] = '\0';

	}
	else
	{
		;
	}
	
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