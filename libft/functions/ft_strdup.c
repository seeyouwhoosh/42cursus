/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiyu <xiyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:13:52 by xwu               #+#    #+#             */
/*   Updated: 2025/06/11 23:48:56 by xiyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	abs_len;

	abs_len = ft_strlen(s) + 1;
	ptr = malloc(abs_len);
	if (!ptr)
		return (NULL);
	while (abs_len)
	{
		abs_len--;
		ptr[abs_len] = s[abs_len];
	}
	return (ptr);
}
