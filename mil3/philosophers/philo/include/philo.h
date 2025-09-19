/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:31:17 by xwu               #+#    #+#             */
/*   Updated: 2025/09/06 12:31:17 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	size_t		id;
	size_t		n_eaten;
	size_t		t_die;
	size_t		t_eat;
	size_t		t_sleep;
	int			n_eat;
	size_t		start_time;
	pthread_t	thread;
}			t_philo;

typedef struct s_house
{
	size_t		n_philo;
	t_philo		*philo;
}					t_house;

int		ft_atoi(const char *str);

size_t	gettime_milisec(void);

void	usleep_milisec(size_t miliseconds);

#endif /* PHILO_H */
