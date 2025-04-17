/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiyu <xiyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:15:22 by xiyu              #+#    #+#             */
/*   Updated: 2025/04/17 01:15:44 by xiyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
