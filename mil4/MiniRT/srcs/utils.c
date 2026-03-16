/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:56:46 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/13 13:45:29 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	add_decimals(char *str, size_t dot, double sign, double *x)
{
	double	decimal;
	size_t	i;

	i = ft_strlen(str);
	decimal = 0;
	while (--i != dot)
	{
		if (str[i] < '0' || str[i] > '9')
			return (UNKNOWN_SPECIFIER);
		decimal = decimal / 10 + str[i] - '0';
	}
	decimal /= 10;
	*x += decimal;
	*x *= sign;
	return (SUCCESS);
}

int	ft_atod(char *str, double *x)
{
	size_t	i;
	double	sign;

	if (!str || !str[0] || !ft_strncmp(".", str, 2)
		|| !ft_strncmp("+.", str, 3) || !ft_strncmp("-.", str, 3))
		return (UNKNOWN_SPECIFIER);
	i = 0;
	sign = 1.0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[i++] == '-')
			sign = -1.0;
	}
	while (str[i] && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (UNKNOWN_SPECIFIER);
		*x = *x * 10.0 + (double)(str[i++] - '0');
		if (*x == INFINITY)
			return (WRONG_SPECIFIER);
	}
	if (str[i])
		return (add_decimals(str, i, sign, x));
	*x *= sign;
	return (SUCCESS);
}

int	ft_ft_atoi(char *str, int *n)
{
	size_t	i;

	*n = 0;
	if (!str || !str[0])
		return (UNKNOWN_SPECIFIER);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (UNKNOWN_SPECIFIER);
		*n = *n * 10 + str[i++] - '0';
		if (*n > 255)
			return (WRONG_SPECIFIER);
	}
	return (SUCCESS);
}

double	mod(double x, double y, double z)
{
	return (x * x + y * y + z * z);
}

int	is_color(int r, int g, int b)
{
	return (r < 256 && r >= 0 && g < 256
		&& g >= 0 && b < 256 && b >= 0);
}
