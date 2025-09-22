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

	philo = (t_philo *)args;
	philo->start_time = gettime_milisec();
	philo->last_time_eat = gettime_milisec();
	while (1)
	{
		printf("%lu	%zu ha empezado su vida\n", gettime_milisec() - philo->start_time, philo->id);
		
		printf("%lu	%zu is sleeping\n", gettime_milisec() - philo->start_time, philo->id);
		usleep_milisec(philo->t_sleep);
		printf("%lu	%zu is thinking\n", gettime_milisec() - philo->start_time, philo->id);
	}
		return (NULL);
}

/* 1. PARSING ARGUMENTS PART */

int	isnumeric(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

/* Checking that the numbers of args are valid, that they are all positive numbers before initializing anything */
int	parse_args(int ac, char **av)
{
	size_t	i;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (++i < ac)
		if (!isnumeric(av[i]))
			return (1);
	if (ft_atoi(av[1] > MAX_N_PHILO))
		return (1);
	return (0);
}

int	house_init(char **av, t_house *house)
{
	size_t	i;
	size_t	j;

	house->n_philo = ft_atoi(av[1]);
	i = -1;
	while (++i < house->n_philo)
	{
		house->philo[i].t_die = ft_atoi(av[2]);
		house->philo[i].t_eat = ft_atoi(av[3]);
		house->philo[i].t_sleep = ft_atoi(av[4]);
		if (av[5])
			house->philo[i].n_eat = ft_atoi(av[5]);
		else
			house->philo[i].n_eat = -1;
	}
	i = -1;
	while (++i < house->n_philo)
		pthread_mutex_init(&house->forks[i], NULL);
	i = -1;
	while (++i < house->n_philo)
	{
		house->philo[i].left_fork = house->forks[i];
		house->philo[i].right_fork = house->forks[i + 1 % house->n_philo];
	}
}

int	main(int ac, char **av)
{
	t_house	house;
	size_t	i;
	int		*retval;

	if (parse_args(ac, av))
	{
		printf("\e[1;31mError\e[0;0m: arguments invalid");
		return (1);
	}
	house_init(av, &house);
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
}
