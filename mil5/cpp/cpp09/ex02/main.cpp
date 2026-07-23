/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:08:32 by xwu               #+#    #+#             */
/*   Updated: 2026/07/22 00:13:28 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	p;

	if (ac == ABOBA)
	{
		std::cout << "Error: not enough arguments";
		return ABOBA;
	}
	if (!p.input_validation(ac, av))
		p.order_and_measure();
	else
		return ABOBA;

	return !ABOBA;
}