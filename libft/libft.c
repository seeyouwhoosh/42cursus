/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:23:07 by xwu               #+#    #+#             */
/*   Updated: 2025/04/12 13:29:38 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is... character classification functions

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}


int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}


int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}


// Testing ground
#include <stdio.h>
int	main(void)
{
	printf("Is '1' numeric? %d\n", ft_isdigit('1'));
	printf("Is 'a' alphabetical? %d\n", ft_isalpha('a'));
	printf("Is 'f' alphanumerical? %d\n", ft_isalnum('f'));
	printf("Is ' ' printable? %d\n", ft_isprint(' '));
	printf("Is ')' ascii? %d\n", ft_isascii(' '));

	printf("Is 'i' numeric? %d\n", ft_isdigit('i'));
	printf("Is '2' alphabetical? %d\n", ft_isalpha('2'));
	printf("Is ';' alphanumerical? %d\n", ft_isalnum(';'));
	printf("Is '\\n' printable? %d\n", ft_isprint('\0'));
	printf("Is 'ó' ascii? %d\n", ft_isascii(129));
	return (0);
}
// End of testing ground

