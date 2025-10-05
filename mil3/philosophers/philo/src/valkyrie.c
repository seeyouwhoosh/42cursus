/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valkyrie_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:01:38 by xwu               #+#    #+#             */
/*   Updated: 2025/10/05 14:01:38 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_has_eaten(t_house *house)
{
	size_t	i;

	i = -1;
	while (++i < house->n_philo)
	{
		pthread_mutex_lock(&house->philo[i].meal_mutex);
		if (house->philo[i].n_eat)
		{
			pthread_mutex_unlock(&house->philo[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&house->philo[i].meal_mutex);
	}
	return (1);
}

void	*valkyrie(void *args)
{
	t_house	*house;
	size_t	i;

	house = (t_house *)args;
	usleep_milisec(10);
	while (!all_has_eaten(house))
	{
		i = -1;
		while (++i < house->n_philo)
		{
			pthread_mutex_lock(&house->philo[i].meal_mutex);
			if (gettime_milisec() - house->philo[i].last_time_eat
				>= house->philo[i].t_die)
			{
				pthread_mutex_lock(&house->dead_mutex);
				house->someone_died = 1;
				printf_action(&house->philo[i], "has died");
				pthread_mutex_unlock(&house->dead_mutex);
				pthread_mutex_unlock(&house->philo[i].meal_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&house->philo[i].meal_mutex);
		}
	}
	return (NULL);
}
