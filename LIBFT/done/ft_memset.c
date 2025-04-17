/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiyu <xiyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:13:09 by xiyu              #+#    #+#             */
/*   Updated: 2025/04/17 11:08:36 by xiyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	index;
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
