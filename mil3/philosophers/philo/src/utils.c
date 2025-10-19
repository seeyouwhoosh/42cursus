/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:30:53 by xwu               #+#    #+#             */
/*   Updated: 2025/10/20 00:50:23 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isnumeric(char *str)
{
	size_t	i;

	if (!str || !(*str))
		return (0);
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	number;
	int	sign;

	index = 0;
	number = 0;
	sign = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign += -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = number * 10 + (str[index] - '0');
		index++;
	}
	return (number * sign);
}

size_t	gettime_milisec(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		write(2, "Error: gettimeofday()\n", 22);
		return (-1);
	}
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	usleep_milisec(size_t miliseconds)
{
	size_t	start_time;

	start_time = gettime_milisec();
	while (gettime_milisec() - start_time < miliseconds)
		usleep(500);
}
