/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:50:31 by xwu               #+#    #+#             */
/*   Updated: 2025/04/12 14:24:37 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL ((void *)0)


int	ft_strlen(const char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}


char	*ft_strchr(const char *s, int c)
{
	const char	*temp_s;

	temp_s = s;
	while (*temp_s)
	{
		if (*temp_s == (char)c)
		{
			return ((char *)temp_s);
		}	
		temp_s++;
	}
	return (NULL);
}


char	*ft_strrchr(const char *s, int c)
{
	const char	*temp_s;
	const char	*ptr_c;

	temp_s = s;
	ptr_c = NULL;
	while (*temp_s)
	{
		if (*temp_s == (char)c)
		{
			ptr_c = temp_s;
		}	
		temp_s++;
	}
	return ((char *) ptr_c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
	}
	return (0);
}


int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	index;

	index = 0;
	while (n != 0 && s1[index] != '\0' && s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			return (s1[index] - s2[index]);
		}
		index++;
		n--;
	}
	return (0);
}


void	*ft_memset(void *b, int c, int n)
{
	int	index;
	unsigned char	*b_copy;

	index = 0;
	b_copy = (unsigned char *)b;
	while (n > index)
	{
		b_copy[index] = (unsigned char)c;
		index++;
	}
	return (b);
}


void	ft_bzero(void *s, int n)
{
	ft_memset(s, 0, n);
}


void	*ft_memchr(const void *s, int c, unsigned int n)
{
	const unsigned char	*s_copy;

	s_copy = (const unsigned char *)s;
	while (n != 0)
	{
		if(*s_copy == (unsigned char)c)
		{
			return ((void *)s_copy);
		}
		n--;
		s_copy++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n != 0)
	{
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	return (0);
}

void    *ft_memcpy(void *restrict dst, const void *restrict src, int n)
{
	int index;
	char *dst_copy;

	dst_copy = (char *)dst;
	index = 0;
	while (n > index && &dst[index] != &src[index])
	{
		dst_copy[index] = ((char *)src)[index];
		index++;
	}
	return (dst);
}

/* // Testing ground
#include <stdio.h>
int	main(void)
{
	char *s = "Hello \0world";
	char s2[] = "Hello \0wow mama";
	int n[] = {1, 2, 3, 4, 5, 6};
	printf("Address of \"Hello World\": %p \n", s);
	printf("o is in %p \n", ft_strchr(s,'o'));
	printf("Last 'o' is in %p \n", ft_strrchr(s,'o'));
	printf("Length: %d\n", ft_strlen(s));
	printf("Comparison: %d\n", ft_strcmp(s, s2));
	printf("Comparison with number: %d\n", ft_strncmp(s, s2, 7));

	ft_memset(n, 0, sizeof(n));
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", n[i]);
	}
	printf("\nLocate: %p\n", ft_memchr(s, 'r', 11));
	printf("Comparison: %d\n", ft_memcmp(s, s2, sizeof(s2)));

	return (0);
}
// End of testing ground */
