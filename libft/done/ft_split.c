/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:55:19 by xwu               #+#    #+#             */
/*   Updated: 2025/04/24 21:21:20 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strwords(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);

	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

void	ft_freesplit(char **words, size_t ls)
{
	while (ls)
	{
		free(words[ls]);
		ls--;
	}
	free(words);
}
void	ft_checkmemory(char *str)
{
	if (!str)
		return (NULL)
}

char	*ft_wordcpy(char *s, size_t j, size_t i)
{
	char	*word;

	word = malloc(i - j + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[i], i - j + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	ls;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_strwords(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	ls = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			result[ls] = ft_wordcpy(s, j, i);
			if (!result[ls])
				return (ft_freesplit(result, ls), NULL);
			ls++;
		}
	}
	result[ls] = NULL;
	return (result);
}

void	ft_putstrstr(char **s, size_t quantity)
{
	size_t	i;

	i = 0;
	while (quantity >= i)
	{
		ft_putstr_fd(s[i], 1);
		if (quantity != i)
			ft_putchar_fd('\n', 1);
		i++;
	}
}
#include <stdio.h>
int main(void)
{
	char *str = "Érase una vez una patata";
	
	char **strstr = ft_split(str, ' ');
	size_t	n = ft_strwords(str, ' ');
	ft_putstrstr(strstr, n);
	ft_freesplit(strstr, n);
	printf("Número de palabras en la frase \"%s\" es %zu", str, ft_strwords(str, ' '));
	return (0);
}