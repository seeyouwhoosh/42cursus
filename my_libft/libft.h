#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>
#include <unistd.h>

/* Character identification */

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_isprint(int c);

int	ft_isascii(int c);

int	ft_isspace(int c);

/* Character conversion */

int	ft_tolower(int c);

int	ft_toupper(int c);

/* Memory management */

void	*ft_memset(void *b, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n);

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);



/* Strings */

int	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int	ft_strcmp(const char *s1, const char *s2);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

/* Special functions */

void ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif 