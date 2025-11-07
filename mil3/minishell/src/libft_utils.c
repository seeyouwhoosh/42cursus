/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:55:19 by xwu               #+#    #+#             */
/*   Updated: 2025/11/07 10:48:42 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

char	*charset_in_str(const char *str, const char *charset)
{
	size_t	i;
	size_t	j;

	if (!str || !charset || !(*charset) || !(*str))
		return (NULL);
	i = -1;
	while (charset[++i])
	{
		j = -1;
		while (str[++j])
		{
			if (charset[i] == str[j])
				return (&str[j]);
		}
	}
	return (NULL);
}

size_t	ft_strwords(const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !ft_isspace(s[i]))
				i++;
		}
	}
	return (count);
}

size_t	ft_strwords_sep(const char *s, const char *charset)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
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

void	ft_freesplit(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	if (size == 0)
	{
		return (i);
	}
	while (size - 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
			{
				return (&((char *)big)[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

static char	*ft_wordcpy(const char *s, size_t j, size_t i)
{
	char	*word;

	word = malloc(i - j + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[j], i - j + 1);
	return (word);
}

char	**ft_split(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	ls;
	char	**result;

	result = malloc((ft_strwords(s) + 1) * sizeof(char *));
	if (!result || !s)
		return (free(result), NULL);
	i = 0;
	ls = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			j = i;
			while (s[i] && !ft_isspace(s[i]))
				i++;
			result[ls++] = ft_wordcpy(s, j, i);
			if (!result[ls - 1])
				return (ft_freesplit(result), NULL);
		}
		else
			i++;
	}
	return (result[ls] = NULL, result);
}

char	**ft_split_sep(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	ls;
	char	**result;

	result = malloc((ft_strwords_sep(s, ':') + 1) * sizeof(char *));
	if (!result || !s)
		return (free(result), NULL);
	i = 0;
	ls = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			result[ls++] = ft_wordcpy(s, j, i);
			if (!result[ls - 1])
				return (ft_freesplit(result), NULL);
		}
		else
			i++;
	}
	return (result[ls] = NULL, result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	total_size;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(total_size);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}



void	ft_putstrstr(char **s, char sep)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(1, s[i], ft_strlen(s[i]));
		if (s[i + 1])
			write(1, &sep, 1);
		i++;
	}
}

/* #include <stdio.h>
int main(void)
{
	char *str = "Hello World";
	
	char **strstr = ft_split(str, ' ');
	size_t	n = ft_strwords(str, ' ');
	ft_putstrstr(strstr, n);
	ft_freesplit(strstr);
	printf("Número de palabras en la frase \"%s\" es %zu", str, n);
	return (0);
}
 */