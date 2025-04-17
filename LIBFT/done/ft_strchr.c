/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiyu <xiyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:14:12 by xiyu              #+#    #+#             */
/*   Updated: 2025/04/17 01:15:09 by xiyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
