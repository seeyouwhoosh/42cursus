/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:20:07 by xwu               #+#    #+#             */
/*   Updated: 2025/04/17 18:11:05 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
	{
		return (dst_len + size);
	}
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
		size--;
	}
	dst[dst_len] = '\0';
	return (dst_len + src_len);
}
