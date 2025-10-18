/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:31:17 by xwu               #+#    #+#             */
/*   Updated: 2025/10/17 22:15:41 by xwu              ###   ########.fr       */
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
typedef struct s_house	t_house;

typedef struct s_philo
{
	size_t		id;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_eat;
	int			n_eaten;
	short		eating;
	size_t		start_time;
	size_t		last_time_eat;
	pthread_t	thread;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		meal_mutex;
	t_mutex		*print_mutex;
	t_mutex		*dead_mutex;
	int			*someone_died;
}				t_philo;

typedef struct s_house
{
	size_t		n_philo;
	t_philo		*philo;
	t_mutex		*forks;
	pthread_t	valkyrie;
	t_mutex		print_mutex;
	t_mutex		dead_mutex;
	int			someone_died;
}				t_house;

/* main_utils.c */
/* Auxiliary functions used for the main, like parsing, initiating stuff */

void	philo_init(char **av, t_house *house);

void	house_init(char **av, t_house *house);

void	threads_create(t_house *house);

void	threads_join(t_house *house);

void	exit_house(t_house *house);

/* utils.c */
/* General purpose functions */

int		ft_atoi(const char *str);

size_t	gettime_milisec(void);

void	usleep_milisec(size_t miliseconds);

/* Function that checks if STR is a natural number (zero included),
does not look for limits */
int		isnumeric(char *str);

/* philo.c */
/* Functions used through all a philosophers life */

void	printf_action(t_philo *philo, char *action);

int		anyone_died(t_philo *philo);

int		grab_forks(t_philo	*philo);

int		eat(t_philo *philo);

void	*philo_life(void *args);

/* valkyrie.c */
/* Functions used  to watch the dying philosopher */

int		all_has_eaten(t_house *house);

int		someone_has_died(t_house *house);

void	*valkyrie(void *args);

#endif /* PHILO_H */
