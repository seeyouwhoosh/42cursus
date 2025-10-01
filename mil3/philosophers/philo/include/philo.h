/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:31:17 by xwu               #+#    #+#             */
/*   Updated: 2025/09/24 21:41:37 by xwu              ###   ########.fr       */
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

# define MAX_N_PHILO 200

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	size_t		id;
	size_t		t_die;
	size_t		t_eat;
	size_t		t_sleep;
	int			n_eat;
	size_t		start_time;
	size_t		last_time_eat;
	pthread_t	thread;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		meal_mutex;
	t_mutex		*print_mutex;
}				t_philo;

typedef struct s_house
{
	size_t		n_philo;
	t_philo		philo[MAX_N_PHILO];
	t_mutex		forks[MAX_N_PHILO];
	pthread_t	valkyrie;
	t_mutex		print_mutex;
}				t_house;

int		ft_atoi(const char *str);

size_t	gettime_milisec(void);

void	usleep_milisec(size_t miliseconds);

int		parse_args(int ac, char **av);

void	printf_action(t_philo *philo, char *action);

#endif /* PHILO_H */
