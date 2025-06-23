#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

size_t	ft_strpdump1(char **line, char *buffer, char *newlinepos) // No funciona
{
	size_t	buffer_len;
	size_t	line_len;
	char	*newline;
	size_t	i;
	size_t	j;

	i = 0;
	line_len = 0;
	if (newlinepos)
		buffer_len = newlinepos - buffer; // el problema es que no pilla si es solo salto de línea
	else
		buffer_len = strlen(buffer);
	if (*line)
		line_len = strlen(*line);
	newline = malloc(buffer_len + line_len + 1);
	if (!newline)
		return (0);
	if (*line)
		while ((*line)[i++])
			newline[i - 1] = (*line)[i - 1];
	j = 0;
	while (j < (buffer_len - line_len))
		newline[i++] = buffer[j++];
	newline[i - 1] = '\0';
	free(*line);
	*line = newline;
	return (i);
}

size_t	ft_strpdump2(char **line, char *buffer, char *newlinepos) //No funciona
{
	char	*newline;
	char	**ogline;
	size_t	i;

	i = 0;
	ogline = line;
	if (!(*line))
	{
		newline = malloc(strlen(buffer) + 1);
		printf("2.1. SIZE: %ld", strlen(buffer));
		printf("2.2. P_NL: %p", newline);
	}
	else
	{
		newline = malloc(strlen(*line) + strlen(buffer) + 1);

		if (!newline)
			return (0);
		while (**line)
			newline[i++] = *(*line)++;
	}
	while (((!newlinepos) && *buffer) || (buffer != newlinepos))
		newline[i++] = *buffer++;
		newline[i] = '\0';
	free(*ogline);
	*ogline = newline;
	return (i);
}


/* Workflow
1. ¿Está buffer vacío? 
	1.1. Sí: retornar line tal y como está.
	1.2. No: proseguir
2. ¿Está line vacía?
	2.2. Sí: solo la parte del buffer relevante
	2.3. No: proseguir
3. ¿Está la posición nl vacía?
	3.1. Sí: concatenar line y buffer tal y como están
	3.2. Concatenar hasta la posición en la que se encuentra el nl
*/


size_t	ft_strpdump3_1(char **line, char *buffer, char *pos_nl)
{
	size_t	n;
	char	*newline;

	if (!buffer)
		return (0);
	if (!pos_nl)
		n = strlen(buffer);
	else
		n = pos_nl - buffer;
	if (*line)
	{
		newline = malloc(strlen(*line) + n + 1);
		newline[0] = '\0';
		newline = strcpy(newline, *line);
	}
	else
	{
		newline = malloc(n + 1);
		newline[0] = '\0';
	}
	newline = strncat(newline, buffer, n);
	free(*line);
	*line = newline;
	return (n);
}

size_t	ft_strpdump3(char **line, char *buffer, char *pos_nl)
{
	size_t	n;
	char	*newline;

	if (!buffer)
		return (0);
	if (!pos_nl)
		n = strlen(buffer);
	else
		n = pos_nl - buffer + 1;
	if (*line)
		newline = malloc(strlen(*line) + n + 1);
	else
		newline = malloc(n + 1);
	newline[0] = '\0';
	if (*line)
		newline = strcpy(newline, *line);
	newline = strncat(newline, buffer, n);
	free(*line);
	*line = newline;
	return (n);
}

int main(void)
{
	char buffer[][128] = {"P", "Sin salto de línea", "Con salto de línea\nen el medio", "Con salto de línea al final\n", "\n", "", " ", "P\n", "Fin."};
	char *line = NULL;

	for (size_t i = 0; i < sizeof(buffer)/128; i++)
	{
		printf("\n%zu. \"%s\"\nPOS: %p\n", i + 1, buffer[i], &buffer[i]);
		char *posnl = ft_pos_nl(buffer[i]);
		printf("POS_NL: %p\n", posnl);
		
		ft_strpdump3(&line, buffer[i], posnl);
		printf("LINE: \"%s\"\n", line);
		free(line);
		line = NULL;
	}
	
	return 0;
}
