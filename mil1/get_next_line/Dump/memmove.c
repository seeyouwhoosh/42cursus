#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


int	main(void)
{
	size_t		n;
	char *pos_nl;
	char buffer[][128] = {"P", "Sin salto de línea", "Con salto de línea\nen el medio", "Con salto de línea al final\n", "\n", "", " ", "P\n", "Fin."};

	for (size_t i = 0; i < sizeof(buffer)/128; i++)
	{
		printf("\n%zu. \"%s\"\n", i + 1, buffer[i]);
		pos_nl = ft_pos_nl(buffer[i]);
		n = strlen(buffer[i]) - (pos_nl - (char *)buffer[i]) + 1;
		ft_gnl_memmove(buffer[i], pos_nl, n);
		printf("BUFFER: \"%s\"\n\
			LEN_BUFFER: %ld\n\
			POS_NL: %ld\n\
			NUMBER MOVED: %ld", 
			buffer[i], strlen(buffer[i]), pos_nl - (char *)buffer[i], n);
	}
	return (0);
}