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
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

typedef struct philo_s
{
	unsigned int    t_die;
	unsigned int    t_eat;
	unsigned int    t_sleep;
	unsigned int    *n_eat;
	pthread_mutex_t *mutex;   // puntero compartido entre todos
	struct timeval  start_time;
	size_t          id;
} philo_t;

long timestamp_ms(struct timeval start)
{
	struct timeval now;
	gettimeofday(&now, NULL);
	long sec  = now.tv_sec - start.tv_sec;
	long usec = now.tv_usec - start.tv_usec;
	return usec;
}

void *life_of_philo(void *arg)
{
	philo_t *philo = (philo_t *)arg;

	printf("%ld ms : philosopher %zu has awaken\n",
		timestamp_ms(philo->start_time), philo->id);

	pthread_mutex_lock(philo->mutex);
	printf("%ld ms : philosopher %zu will now eat something\n",
		timestamp_ms(philo->start_time), philo->id);

	if (*(philo->n_eat) > 0)
	{
		printf("%d\n", *philo->n_eat);
		*(philo->n_eat)--;
		printf("%ld ms : philosopher %zu has eaten\n",
			timestamp_ms(philo->start_time), philo->id);
	}
	else
	{
		printf("%ld ms : philosopher %zu didn't find any food\n",
		timestamp_ms(philo->start_time), philo->id);
	}
		pthread_mutex_unlock(philo->mutex);

	return NULL;
}

int main(int ac, char **av)
{
	if (ac < 6)
	{
		fprintf(stderr, "Usage: %s n_philo t_die t_eat t_sleep n_eat\n", av[0]);
		return 1;
	}

	unsigned int n_philo = atoi(av[1]);
	unsigned int t_die   = atoi(av[2]);
	unsigned int t_eat   = atoi(av[3]);
	unsigned int t_sleep = atoi(av[4]);
	unsigned int n_eat   = atoi(av[5]);

	pthread_t *threads = malloc(sizeof(pthread_t) * n_philo);
	philo_t   *philos  = malloc(sizeof(philo_t) * n_philo);
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);

	struct timeval start_time;
	gettimeofday(&start_time, NULL);

	for (size_t i = 0; i < n_philo; i++)
	{
		philos[i].id        = i + 1;
		philos[i].t_die     = t_die;
		philos[i].t_eat     = t_eat;
		philos[i].t_sleep   = t_sleep;
		philos[i].n_eat     = &n_eat;
		philos[i].mutex     = &mutex;
		philos[i].start_time = start_time;

		pthread_create(&threads[i], NULL, life_of_philo, &philos[i]);
	}

	for (size_t i = 0; i < n_philo; i++)
		pthread_join(threads[i], NULL);

	pthread_mutex_destroy(&mutex);
	free(threads);
	free(philos);
	return 0;
}
