/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:39:42 by xwu               #+#    #+#             */
/*   Updated: 2025/04/16 19:41:51 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	const unsigned char	*s_copy;

	s_copy = (const unsigned char *)s;
	while (n != 0)
	{
		if (*s_copy == (unsigned char)c)
		{
			return ((void *)s_copy);
		}
		n--;
		s_copy++;
	}
	return (NULL);
}
