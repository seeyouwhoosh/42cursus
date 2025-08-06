/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/04/19 20:47:48 by xwu              ###   ########.fr       */
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

int	ft_power(int base, int exp)
{
	int	n;

	n = 1;
	while (exp)
	{
		n *= base;
		exp --;
	}
	return (n);
}

int	is_int(char *s)
{
	int	conv;
	int	i;
	int	sign;

	sign = 0;
	i = ft_strlen(s);
	conv = ft_atoi(s);
	if (s[0] == '-')
	{
		if (conv > 0)
			return (0);
		sign = 1;
	}
	conv = abs(conv);
	while (i > sign)
	{
		if ((s[i - 1] - '0') != (conv % 10))
			return (0);
		conv /= 10;
		i--;
	}
	return (1);
}
