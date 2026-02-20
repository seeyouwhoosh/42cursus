#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

// devuelve la posición del newline, y si no, del EOF
size_t	pos_newline(char *buffer)
{
	size_t	i = 0;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	return (i);
}

void	mmemmove(char *buffer, char *line, int n)
{
	size_t	i = 0;

	while (n > i)
	{
		line[i] = buffer[i];
		i++;
	}
}

size_t	ft_strlen(char *line)
{
	size_t i = 0;

	if (!line)
		return (0);
	while (line[i])
		i++;
	return (i);
}

char	*ft_str_realloc(char *old, size_t new_size)
{
	char	*line = malloc(new_size + 1);
	if (!line)
		return (NULL);
	size_t	i = 0;
	while (old[i])
	{
		line[i] = old[i];
		i++;
	}
	while (new_size >= i)
	{
		line[i] = 0;
		i++;
	}
	return (line);
}

int		there_is_nl(char *buffer)
{
	size_t	i = 0;

	while (buffer[i])
		if (buffer[i] == '\n')
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	size_t	n_read = 0;
	char	*line = NULL;
	size_t	n_move = 0;

	if (buffer[0]) // dumpear lo que haya quedado y si tiene newline, devolver
	{
		short	nl = there_is_nl(buffer);
		size_t	n_move = pos_newline(buffer);
		if (n_move)
			line = malloc(n_move + 1 + nl);
		if (!line)
			return (NULL);
		mmemmove(buffer, line, n_move + nl);
		line[n_move + nl] = 0;
		if (nl)
		{
			mmemmove(buffer + n_move + nl, buffer, ft_strlen(buffer) - n_move - nl);
			buffer[ft_strlen(buffer) - n_move - nl] = 0;
			return (line);
		}
	}

	n_read = read(fd, buffer, BUFFER_SIZE);
	if (n_read == -1)
		return (NULL);
	buffer[BUFFER_SIZE] = 0;
	n_move = pos_newline(buffer);

	while (ft_strlen(buffer) == n_move)
	{
		size_t	total_len = ft_strlen(line) + n_move + 1;
		line = ft_str_realloc(line, total_len);
		mmemmove(buffer, line, n_move + 1);
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
			return (NULL);
		buffer[BUFFER_SIZE] = 0;
		n_move = pos_newline(buffer);
	}
	size_t	total_len = ft_strlen(line) + n_move + 1;
	line = ft_str_realloc(line, total_len);

	mmemmove(buffer, line + ft_strlen(line), n_move + 1);
	mmemmove(buffer + n_move, buffer, ft_strlen(buffer) - n_move);
	buffer[ft_strlen(buffer) - n_move] = 0;
	return (line);
}
