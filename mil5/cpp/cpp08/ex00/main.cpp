/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:50:06 by xwu               #+#    #+#             */
/*   Updated: 2026/06/19 15:50:06 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "CREATING CONTAINERS OF INTS\n";
	std::vector<int> v;
	for (int i = 0; i < 100; i++)
		v.push_back(i);
	std::list<int> l;
	for (int i = 0; i < 100; i++)
		l.push_back(i);
	std::deque<int> d;
	for (int i = 0; i < 100; i++)
		d.push_back(i);

	std::cout << "TESTS\n";

	std::cout << "Vectors\n";
	try
	{
		std::cout << *easyfind(v, 0) << "\n";
		std::cout << *easyfind(v, 42) << "\n";
		std::cout << *easyfind(v, 100) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "Lists\n";
	try
	{
		std::cout << *easyfind(l, 0) << "\n";
		std::cout << *easyfind(l, 42) << "\n";
		std::cout << *easyfind(l, 100) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	std::cout << "Deques\n";
	try
	{
		std::cout << *easyfind(d, 0) << "\n";
		std::cout << *easyfind(d, 42) << "\n";
		std::cout << *easyfind(d, 100) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}