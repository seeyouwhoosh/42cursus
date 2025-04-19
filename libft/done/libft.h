/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:15:17 by xwu               #+#    #+#             */
/*   Updated: 2025/04/19 18:43:27 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

/* Character identification */

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isprint(int c);

int		ft_isascii(int c);

/* Character conversion */

int		ft_tolower(int c);

int		ft_toupper(int c);

/* Outputting */

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int nb, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

/* Memory management */

void	*ft_memset(void *b, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

/* Strings */

int		ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

/* Memory management specific functions */

void	*ft_calloc(size_t nmemb, size_t size);

/* Special functions */

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif 