/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:50:16 by xwu               #+#    #+#             */
/*   Updated: 2025/10/05 13:50:16 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_action(t_philo *philo, char *action)
{
	size_t	timestamp;

	pthread_mutex_lock(philo->print_mutex);
	timestamp = gettime_milisec() - philo->start_time;
	printf("%lu	%zu %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(philo->print_mutex);
}

int	someone_died(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(philo->dead_mutex);
	dead = *(philo->someone_died);
	pthread_mutex_unlock(philo->dead_mutex);
	return (dead);
}

void	grab_forks(t_philo	*philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		if (someone_died(philo))
			return ;
		printf_action(philo, "has taken a fork");
		if (someone_died(philo))
			return ;
		pthread_mutex_lock(philo->right_fork);
		printf_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		if (someone_died(philo))
			return ;
		printf_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		if (someone_died(philo))
			return ;
		printf_action(philo, "has taken a fork");
	}
}

void	philo_eating(t_philo *philo)
{
	if (someone_died(philo))
		return ;
	grab_forks(philo);
	if (someone_died(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	printf_action(philo, "is eating");
	usleep_milisec(philo->t_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->n_eat != -1 && philo->n_eat)
		philo->n_eat--;
	philo->last_time_eat = gettime_milisec();
	pthread_mutex_unlock(&philo->meal_mutex);

	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*philo_life(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo->last_time_eat = philo->start_time;
	while (!someone_died(philo))
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (!philo->n_eat)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		if (someone_died(philo))
			return (NULL);
		philo_eating(philo);
		if (someone_died(philo))
			return (NULL);
		printf_action(philo, "is sleeping");
		usleep_milisec(philo->t_sleep);
		if (someone_died(philo))
			return (NULL);
		printf_action(philo, "is thinking");
	}
	return (NULL);
}
