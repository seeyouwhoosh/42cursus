/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:07:21 by xwu               #+#    #+#             */
/*   Updated: 2025/09/24 22:03:57 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo	*philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		printf_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		printf_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		printf_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		printf_action(philo, "has taken a fork");
	}
}

/* Risky area, everything is broken */
/* --------------------------------------------- */

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

	return ;
}

int	someone_died(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(philo->dead_mutex);
	dead = *(philo->someone_died);
	pthread_mutex_unlock(philo->dead_mutex);
	return (dead);
}

int	all_has_eaten(t_house *house)
{
	size_t	i;

	i = -1;
	while (++i < house->n_philo)
	{
		pthread_mutex_lock(&house->philo[i].meal_mutex);
		if (house->philo[i].n_eat && house->philo[i].n_eat != -1)
		{
			pthread_mutex_unlock(&house->philo[i].meal_mutex);
			return (0);
		}
	}
	return (1);
}

void	*valkyrie(void *args)
{
	t_house	*house;
	size_t	i;

	house = (t_house *)args;
	usleep_milisec(10);
	while (all_has_eaten(house))
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
				pthread_mutex_unlock(&house->dead_mutex);
				pthread_mutex_unlock(&house->philo[i].meal_mutex);
				printf_action(&house->philo[i], "has died");
				pthread_mutex_lock(&house->print_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&house->philo[i].meal_mutex);
		}
	}
}


void	philo_eating(t_philo *philo)
{
	grab_forks(philo);
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
		philo_eating(philo);
		printf_action(philo, "is sleeping");
		usleep_milisec(philo->t_sleep);
		printf_action(philo, "is thinking");
	}
	return (NULL);
}


void	house_init(char **av, t_house *house)
{
	size_t	i;

	house->n_philo = ft_atoi(av[1]);
	house->someone_died = 0;
	i = -1;
	while (++i < house->n_philo)
		pthread_mutex_init(&house->forks[i], NULL);
	pthread_mutex_init(&house->print_mutex, NULL);
	pthread_mutex_init(&house->dead_mutex, NULL);
	i = -1;
	while (++i < house->n_philo)
	{
		house->philo[i].t_die = ft_atoi(av[2]);
		house->philo[i].t_eat = ft_atoi(av[3]);
		house->philo[i].t_sleep = ft_atoi(av[4]);
		house->philo[i].n_eat = -1;
		if (av[5])
			house->philo[i].n_eat = ft_atoi(av[5]);
		house->philo[i].id = i + 1;
		pthread_mutex_init(&house->philo[i].meal_mutex, NULL);
		house->philo[i].print_mutex = &house->print_mutex;
		house->philo[i].dead_mutex = &house->dead_mutex;
		house->philo[i].left_fork = &house->forks[i];
		house->philo[i].right_fork = &house->forks[(i + 1) % house->n_philo];
		house->philo[i].someone_died = &house->someone_died;
	}
}

int	main(int ac, char **av)
{
	t_house	house;
	size_t	i;
	int		*retval;

	if (parse_args(ac, av))
		return (printf("\e[1;31mError\e[0;0m: arguments invalid"));

	house_init(av, &house);

	if (pthread_create(&house.valkyrie, NULL, valkyrie, &house))
		printf("\e[1;31mError\e[0;0m: pthread_create failed\n");

	i = -1;
	while (house.n_philo > ++i)
	{
		house.philo[i].start_time = gettime_milisec();
		if (pthread_create(&house.philo[i].thread, NULL,
				philo_life, &house.philo[i]))
			printf("\e[1;31mError\e[0;0m: pthread_create failed\n");
	}
	i = -1;
	pthread_join(house.valkyrie, (void **)&retval);
	while (house.n_philo > ++i)
		pthread_detach(house.philo[i].thread);
	exit_house(&house);
}
