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
# include <sys/time.h>

typedef struct s_house
{
	size_t			n_philo;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	int				n_eat;
	unsigned int	start_time;
}					t_house;

typedef struct s_philo
{
	size_t	id;
	size_t	n_eaten;
}			t_philo;

int				ft_atoi(const char *str);

unsigned int	gettime_milisec(void);

#endif /* PHILO_H */
