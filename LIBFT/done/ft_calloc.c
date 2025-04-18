/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:15:05 by xwu               #+#    #+#             */
/*   Updated: 2025/04/18 18:50:26 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#define MAX_INT 2147483647

void	*calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (size != 0 && nmemb > MAX_INT / size)
	{
		return (NULL);
	}
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	while (total_size)
	{
		total_size--;
		((char *)ptr)[total_size] = 0;
	}
	return (ptr);
}
