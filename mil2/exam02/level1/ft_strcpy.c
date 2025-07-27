#include <stdio.h>
#include <stdlib.h>
char    *ft_strcpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	return (dest);
}

int main(void)
{
	char *str1 = malloc(6);
	char *str2 = "Holla!";

	printf("%s", ft_strcpy(str1, str2));
	return (0);
}