/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:00 by xwu               #+#    #+#             */
/*   Updated: 2026/07/11 19:40:35 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	(void)other;
	return (*this);
}

void	PmergeMe::order_and_measure()
{
	clock_t	v_start;
	clock_t	v_finish;
	clock_t	l_start;
	clock_t	l_finish;

	v_start = clock();
	v_merge_insertion();
	v_finish = clock();
	l_start = clock();
	l_merge_insertion();
	l_finish = clock();
	
	std::cout << "Before:	" << av;
	std::cout << "After:	" << v;

	std::cout << "Time to process a range of " << size << " elements with std::vector :" << (v_finish - v_start) / CLOCKS_PER_SEC << "s\n";
	std::cout << "Time to process a range of " << size << " elements with std::vector :" << (l_finish - l_start) / CLOCKS_PER_SEC << "s\n";
}

std::ostream &operator<<(std::ostream &os, char **av)
{
	while (av)
	{
		os << *av;
		if (*(av + 1) != NULL)
			os << " ";
		av++;
	}
	return os;
}

std::ostream &operator<<(std::ostream &os, std::vector<int> v)
{
	std::vector<int>::iterator	it = v.begin();
	while (it != v.end())
	{
		os << *it;
		if (it + 1 != v.end())
			os << " ";
		it++;
	}
	return os;
}