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
	size_t	full_bellies;

	i = -1;
	full_bellies = 0;
	if (house->philo[0].n_eat == -1)
		return (0);
	while (++i < house->n_philo)
	{
		pthread_mutex_lock(&house->philo[i].meal_mutex);
		full_bellies += (house->philo[i].n_eaten == house->philo[i].n_eat);
		pthread_mutex_unlock(&house->philo[i].meal_mutex);
	}
	return (full_bellies == house->n_philo);
}

int	someone_has_died(t_house *house)
{
	size_t	i;
	size_t	last_time_eat;
	short	eating;

	i = -1;
	while (++i < house->n_philo)
	{
		pthread_mutex_lock(&house->philo[i].meal_mutex);
		last_time_eat = gettime_milisec() - house->philo[i].last_time_eat;
		eating = house->philo[i].eating;
		pthread_mutex_unlock(&house->philo[i].meal_mutex);
		if (last_time_eat >= house->philo[i].t_die && !eating)
		{
			pthread_mutex_lock(&house->dead_mutex);
			*house->philo[i].someone_died = 1;
			pthread_mutex_unlock(&house->dead_mutex);
			printf_action(&house->philo[i], "has died");
			return (1);
		}
	}
	return (0);
}

void	*valkyrie(void *args)
{
	t_house	*house;

	house = (t_house *)args;
	usleep_milisec(1);
	while (1)
		if (all_has_eaten(house) || someone_has_died(house))
			break ;
	return (NULL);
}
