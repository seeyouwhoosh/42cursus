/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:59:16 by xwu               #+#    #+#             */
/*   Updated: 2025/04/25 13:04:25 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (start > end && ft_strchr(set, s1[end]))
	{
		end--;
	}
	trimmed = malloc(sizeof(char) * (end - start + 1));
	ft_strlcpy(trimmed, &s1[start], end - start + 1);
	return (trimmed);
}
/*
int main(void)
{
const char *str1 = "                      hello world      ;           ";
const char *set = " ";

printf("%s",ft_strtrim(str1, set));
return 0;
}
*/
