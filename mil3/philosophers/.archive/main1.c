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


/* Falta ponerlo un poco más sofisticado, creo */
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

int	args_parse(t_house *house, char **av)
{
	size_t	i;

	i = 0;
	while (av[++i])
	{
		if (!isnumeric(av[i]))
			return (-1);
	}
	house->n_philo = ft_atoi(av[1]);
	house->t_die = ft_atoi(av[2]);
	house->t_eat = ft_atoi(av[3]);
	house->t_sleep = ft_atoi(av[4]);
	if (av[5])
		house->n_eat = ft_atoi(av[5]);
	else
		house->n_eat = -1;
	return (0);
}

void	*philo_life(void *args)
{
	t_house	*house;
	size_t	philo_id;

	house = (t_house *)args;

	philo_id = house->philo->id + 1;


	unsigned int	current_t;
	current_t = gettime_milisec();
	printf("%u	%zu ha empezado su vida\n", current_t - house->start_time, philo_id);
	usleep(19);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_house		house;
	pthread_t	*threads;

	if (ac < 5 || ac > 6)
	{
		printf("\e[0;1mCorrect usage:\e[0;0m\n./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] \e[0;2m[number_of_times_each_philosopher_must_eat]\e[0;0m\n\e[0;1mExample:\e[0;0m\n./philo 4 310 200 100");
		return (1);
	}
	if (args_parse(&house, av))
	{
		printf("Argument parsing failure");
		return (1);
	}

	printf("-------------------------------------------\nInitializing Philosophers with:\nn_philo: %ld\nt_die: %ld\nt_eat: %ld\nt_sleep: %ld\nn_eat: %d\n-------------------------------------------\n", house.n_philo, house.t_die, house.t_eat, house.t_sleep, house.n_eat);

	threads = (pthread_t *) malloc(sizeof(pthread_t) * house.n_philo);
	house.philo = (t_philo *) malloc(sizeof(t_philo) * house.n_philo);
	if (!threads)
		printf("Error: malloc()");
	house.start_time = gettime_milisec();
	
	size_t	i;
	i = 0;
	while (house.n_philo > i)
	{
		house.philo[i].id = i;
		pthread_create(&threads[i], NULL, philo_life, &house);
		i++;
	}
	i = 0;
	int	*retval;
	while (house.n_philo > i)
	{
		pthread_join(threads[i], (void **)&retval);
		if (retval)
			printf("Thread number %ld has exited with error", i + 1);
		i++;
	}
}
