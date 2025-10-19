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

	if (anyone_died(philo))
		return ;
	pthread_mutex_lock(philo->print_mutex);
	timestamp = gettime_milisec() - philo->start_time;
	printf("%lu	%zu	%s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(philo->print_mutex);
}

int	anyone_died(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(philo->dead_mutex);
	dead = *(philo->someone_died);
	pthread_mutex_unlock(philo->dead_mutex);
	return (dead);
}

int	grab_forks(t_philo	*philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (anyone_died(philo))
		return (pthread_mutex_unlock(philo->left_fork), 1);
	printf_action(philo, "has taken a fork");
	if (philo->left_fork == philo->right_fork)
	{
		usleep_milisec(philo->t_die);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	if (anyone_died(philo))
		return (pthread_mutex_unlock(philo->right_fork),
			pthread_mutex_unlock(philo->left_fork), 1);
	printf_action(philo, "has taken a fork");
	return (0);
}

int	eat(t_philo *philo)
{
	if (grab_forks(philo))
	return (1);
	pthread_mutex_lock(&philo->meal_mutex);
	printf_action(philo, "is eating");
	philo->last_time_eat = gettime_milisec();
	philo->eating = 1;
	pthread_mutex_unlock(&philo->meal_mutex);
	usleep_milisec(philo->t_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->n_eat > 0)
		philo->n_eaten++;
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

void	*philo_life(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2)
		usleep_milisec(1);
	while (!anyone_died(philo))
	{
		if (philo->n_eat != -1 && philo->n_eaten >= philo->n_eat)
			return (NULL);
		eat(philo);
		if (anyone_died(philo))
			return (NULL);
		printf_action(philo, "is sleeping");
		usleep_milisec(philo->t_sleep);
		if (anyone_died(philo))
			return (NULL);
		printf_action(philo, "is thinking");
	}
	return (NULL);
}
