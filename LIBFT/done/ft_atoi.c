/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:15:12 by xwu               #+#    #+#             */
/*   Updated: 2025/04/16 19:22:05 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	number;
	int	sign;

	index = 0;
	number = 0;
	sign = 1;
	while (ft_isspace(str[index]))
	{
		index++;
	}
	while (str[index] == '-' || str[0] == '+')
	{
		if (str[index] == '-')
		{
			sign = -1;
		}
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		number = number * 10 + (str[index] - '0');
		index++;
	}
	return (number * sign);
}
