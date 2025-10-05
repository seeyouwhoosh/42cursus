/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:07:21 by xwu               #+#    #+#             */
/*   Updated: 2025/10/05 14:08:37 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int ac, char **av)
{
	t_house	house;

	if (parse_args(ac, av))
		return (printf("\e[1;31mError\e[0;0m: arguments invalid"));
	house_init(av, &house);
	threads_create(&house);
	threads_join(&house);
	exit_house(&house);
}
