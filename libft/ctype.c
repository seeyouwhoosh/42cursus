/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:23:07 by xwu               #+#    #+#             */
/*   Updated: 2025/04/12 13:29:38 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}


int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}


int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}


int	ft_isspace(int c)
{
	return (c == ' '  || c == '\t' || c == '\n' || 
			c == '\v' || c == '\f' || c == '\r') ;
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}


int	ft_toupper(int c)
{
	if (c >= 'c' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}



/* // Testing ground
#include <stdio.h>
int	main(void)
{
	int character = 's';

	printf("numeric? %d\n", ft_isdigit(character));
	printf("alphabetical? %d\n", ft_isalpha(character));
	printf("alphanumerical? %d\n", ft_isalnum(character));
	printf("printable? %d\n", ft_isprint(character));
	printf("ascii? %d\n", ft_isascii(character));
	printf("lowercase: %c\n", ft_tolower(character));
	return (0);
}
// End of testing ground */

