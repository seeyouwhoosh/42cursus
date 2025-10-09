/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:07:21 by xwu               #+#    #+#             */
/*   Updated: 2025/10/05 21:51:20 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
		return (1);
	i = 0;
	while (++i < ac)
		if (!isnumeric(av[i]))
			return (1);
	if (ft_atoi(av[1]) > MAX_N_PHILO || !ft_atoi(av[1]))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_house	house;

	if (parse_args(ac, av))
		return (printf("\e[1;31mError\e[0;0m: arguments invalid\n"));
	house_init(av, &house);
	threads_create(&house);
	threads_join(&house);
	exit_house(&house);
}
