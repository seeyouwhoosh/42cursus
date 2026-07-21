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

	std::srand(time(NULL));
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

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	
	std::cout << max << " - " << min << " = " << max - min << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << "----------------------------------------\n";
	std::vector<int>	v;
	for (size_t i = 0; i < 5; i++)
	{
		n = std::rand() % 10;
		v.push_back(n);
		std::cout << n << "\n";
	}
	Span	sp2(v.size());
	sp2.addNumber(v.begin(), v.end());

	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

	return (0);
}