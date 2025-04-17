/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:13:03 by xwu               #+#    #+#             */
/*   Updated: 2025/04/17 19:23:06 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((char *)little == NULL)
	{
		return ((char *)big);
	}
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] == little[i + j] && i + j < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)big + 1);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
