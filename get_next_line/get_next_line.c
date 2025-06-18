/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/06/18 16:35:38 by xwu              ###   ########.fr       */
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
	while (line[i]++)
		if (line[i] == c)
			return (i);
	return (-1);
}

size_t	ft_strlen(char *str)
{
	size_t	n;

	while (*str++)
		n++;
	return (n);


/*

Function prototype(fd)

return puntero1


*/

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

