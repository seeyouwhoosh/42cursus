/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:30:53 by xwu               #+#    #+#             */
/*   Updated: 2025/09/19 17:30:56 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* All utils, organizar más tarde */

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	isnumeric(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
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
	while (ft_isspace(str[index]))
		index++;
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign += -1;
		index++;
	}
	while (ft_isdigit(str[index]))
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

int	parse_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (++i < ac)
		if (!isnumeric(av[i]))
			return (1);
	if (ft_atoi(av[1]) > MAX_N_PHILO || !ft_atoi(av[1]))
		return (1);
	return (0);
}

void	printf_action(t_philo *philo, char *action)
{
	size_t	timestamp;

	timestamp = gettime_milisec() - philo->start_time;
	pthread_mutex_lock(philo->print_mutex);
	printf("%lu	%zu %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(philo->print_mutex);
}
