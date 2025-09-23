/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/08/10 01:05:48 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	return (x * ((x > 0) - (x < 0)));
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	is_int(char *s)
{
	int	conv;
	int	i;
	int	sign;

	if (!s || !*s)
		return (0);
	sign = (s[0] == '-');
	i = ft_strlen(s);
	conv = ft_atoi(s);
	if (conv == -2147483648)
		return (sign && !ft_strncmp(s, "-2147483648", 11));
	if ((sign && conv >= 0) || (!sign && conv < 0))
		return (0);
	if (conv < 0)
		conv = -conv;
	while (i-- > sign)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		if ((s[i] - '0') != (conv % 10))
			return (0);
		conv /= 10;
	}
	return (1);
}
