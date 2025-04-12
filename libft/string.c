/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:50:31 by xwu               #+#    #+#             */
/*   Updated: 2025/04/12 14:24:37 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL ((void *)0)

char	*ft_strchr(const char *s, int c)
{
	const char	*temp_s;

	temp_s = s;
	while (*temp_s)
	{
		if (*temp_s == c)
		{
			return ((char *)temp_s);
		}	
		temp_s++;
	}
	return (NULL);
}


char	*ft_strrchr(const char *s, int c)
{
	const char	*temp_s;
	const char	*ptr_c;

	temp_s = s;
	ptr_c = NULL;
	while (*temp_s)
	{
		if (*temp_s == c)
		{
			ptr_c = temp_s;
		}	
		temp_s++;
	}
	return ((char *) ptr_c);
}

// Testing ground
#include <stdio.h>
int	main(void)
{
	char *s = "Hello world";
	printf("Address of \"Hello World\": %p \n", s);
	printf("o is in %p \n", ft_strchr(s,'o'));
	printf("Last 'o' is in %p \n", ft_strrchr(s,'o'));
	return (0);
}
// End of testing ground
