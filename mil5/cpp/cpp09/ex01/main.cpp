/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:56:14 by xwu               #+#    #+#             */
/*   Updated: 2026/07/11 12:47:43 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	RPN	rpn;

	if (ac != 2)
	{
		std::cerr << "Error: wrong number of arguments";
		return 1;
	}

	if (rpn.calculate(av[1]))
		return 1;

	return 0;
}