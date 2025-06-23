#include <stdio.h>
#include <string.h>
#include <stdlib.h>


size_t	ft_strpdump1(char **line, char *buffer, char *newlinepos)
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

size_t	ft_strpdump2(char **line, char *buffer, char *newlinepos)
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

int main(void)
{

	char buffer[][128] = {"P", "Sin salto de línea", "Con salto de línea\nen el medio", "Con salto de línea al final\n", "\n", "", " ", "Fin."};
	char *line = NULL;

	for (size_t i = 0; i < sizeof(buffer)/128; i++)
	{
		printf("\n%zu. \"%s\"\n", i + 1, buffer[i]);
		char *posnl = ft_pos_nl(buffer[i]);
		printf("POS_NL: %p\n", posnl);
			}
	return 0;
}
