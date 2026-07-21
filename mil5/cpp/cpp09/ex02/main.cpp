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

/*
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us

containers: list vector
*/

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