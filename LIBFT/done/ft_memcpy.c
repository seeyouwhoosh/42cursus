/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:54:04 by xwu               #+#    #+#             */
/*   Updated: 2025/04/17 16:54:17 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t		index;
	char		*dst_copy;
	const char	*src_copy;

	dst_copy = (char *)dst;
	src_copy = (const char *)src;
	index = 0;
	while (n > index)
	{
		dst_copy[index] = src_copy[index];
		index++;
	}
	return (dst);
}
