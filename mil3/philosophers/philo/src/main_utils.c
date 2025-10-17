/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:37:58 by xwu               #+#    #+#             */
/*   Updated: 2025/10/05 13:37:58 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(char **av, t_house *house)
{
	size_t	i;

	i = -1;
	while (++i < house->n_philo)
	{
		pthread_mutex_init(&house->philo[i].meal_mutex, NULL);
		house->philo[i].t_die = ft_atoi(av[2]);
		house->philo[i].t_eat = ft_atoi(av[3]);
		house->philo[i].t_sleep = ft_atoi(av[4]);
		house->philo[i].n_eat = -1;
		if (av[5])
			house->philo[i].n_eat = ft_atoi(av[5]);
		house->philo[i].eating = 0;
		house->philo[i].n_eaten = 0;
		house->philo[i].id = i + 1;
		house->philo[i].print_mutex = &house->print_mutex;
		house->philo[i].dead_mutex = &house->dead_mutex;
		house->philo[i].left_fork = &house->forks[i];
		house->philo[i].right_fork = &house->forks[(i + 1) % house->n_philo];
		house->philo[i].someone_died = &house->someone_died;
	}
}

void	house_init(char **av, t_house *house)
{
	size_t	i;

	house->n_philo = ft_atoi(av[1]);
	house->philo = (t_philo *)malloc(sizeof(t_philo) * house->n_philo);
	house->forks = (t_mutex *)malloc(sizeof(t_mutex) * house->n_philo);
	house->someone_died = 0;
	i = -1;
	pthread_mutex_init(&house->print_mutex, NULL);
	pthread_mutex_init(&house->dead_mutex, NULL);
	while (++i < house->n_philo)
		pthread_mutex_init(&house->forks[i], NULL);
	philo_init(av, house);
}

void	threads_create(t_house *house)
{
	size_t	i;

	if (pthread_create(&house->valkyrie, NULL, valkyrie, house))
		printf("\e[1;31mError\e[0;0m: pthread_create failed\n");
	i = -1;
	while (house->n_philo > ++i)
	{
		pthread_mutex_lock(&house->print_mutex);
		house->philo[i].start_time = gettime_milisec();
		house->philo[i].last_time_eat = gettime_milisec();
		pthread_mutex_unlock(&house->print_mutex);
		if (pthread_create(&house->philo[i].thread, NULL,
				philo_life, &house->philo[i]))
			printf("\e[1;31mError\e[0;0m: pthread_create failed\n");
	}
}

void	threads_join(t_house *house)
{
	size_t	i;

	if (pthread_join(house->valkyrie, NULL))
		printf("\e[1;31mError\e[0;0m: pthread_join failed\n");
	i = -1;
	while (house->n_philo > ++i)
		if (pthread_join(house->philo[i].thread, NULL))
			printf("\e[1;31mError\e[0;0m: pthread_join failed\n");
}

void	exit_house(t_house *house)
{
	size_t	i;

	i = -1;
	while (house->n_philo > ++i)
	{
		pthread_mutex_destroy(&house->forks[i]);
		pthread_mutex_destroy(&house->philo[i].meal_mutex);
	}
	pthread_mutex_destroy(&house->print_mutex);
	pthread_mutex_destroy(&house->dead_mutex);
	free(house->philo);
	free(house->forks);
}
