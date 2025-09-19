/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:07:21 by xwu               #+#    #+#             */
/*   Updated: 2025/09/07 11:07:29 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo	*philo)
{
	if (philo->id % 2)
	{
		izquierda;
		derecha;
	}
	else
	{
		derecha;
		izquierda;
	}
}

void	*philo_life(void *args)
{
	t_philo	*philo;
	size_t	last_time_eat;

	philo = (t_philo *)args;
	philo->start_time = gettime_milisec();
	last_time_eat = philo->start_time;
	while (philo->n_eaten && gettime_milisec - last_time_eat < philo->t_die)
	{
		printf("%lu	%zu ha empezado su vida\n", gettime_milisec() - philo->start_time, philo->id);
		grab_forks(philo);
		printf("%lu	%zu is sleeping\n", gettime_milisec() - philo->start_time, philo->id);
		printf("%lu	%zu is sleeping\n", gettime_milisec() - philo->start_time, philo->id);
		usleep_milisec(philo->t_sleep);
	}
		return (NULL);
}

int	main(int ac, char **av)
{
	t_house	house;
	size_t	i;
	int		*retval;

	house.n_philo = ft_atoi(av[1]);
	house.philo = (t_philo *) malloc(sizeof(t_philo) * house.n_philo);
	if (!house.philo)
		printf("Error: malloc()");

	i = 0;
	while (house.n_philo > i)
	{
		house.philo[i].id = i + 1;
		house.philo[i].start_time = gettime_milisec();
		pthread_create(&house.philo[i].thread, NULL,
			philo_life, &house.philo[i]);
		i++;
	}

/* Retrieving threads */
	i = 0;
	while (house.n_philo > i)
	{
		pthread_join(house.philo[i].thread, (void **)&retval);
		if (retval)
			printf("Thread number %ld has exited with error", i + 1);
		i++;
	}
	free(house.philo);
}
