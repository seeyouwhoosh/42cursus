/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:50:08 by xwu               #+#    #+#             */
/*   Updated: 2026/06/19 15:50:08 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <climits>

int main()
{
/* 	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl; */

	Span			sp(100);
	int	n;
	int	max = 0;
	int	min = INT_MAX;

	for (size_t i = 0; i < 99; i++)
	{
		n = std::rand();
		max = n > max ? n : max;
		min = min > n ? n : min;
		sp.addNumber(n);
		std::cout << n << "\n";
	}
	sp.addNumber(n);
	std::cout << n << "\n";
	std::cout << "----------------------------------------\n";

	std::cout << sp.shortestSpan() << std::endl;
	
	std::cout << max << " - " << min << " = " << max - min << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return (0);
}