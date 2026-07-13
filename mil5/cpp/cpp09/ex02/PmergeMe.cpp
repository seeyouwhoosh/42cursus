/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:00 by xwu               #+#    #+#             */
/*   Updated: 2026/07/13 19:10:27 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ORTHODOX CANONICAL CLASS */
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

/* VECTOR VERSION */

void	PmergeMe::v_merge_insertion()
{
	;
}

/* LIST VERSION */

void	PmergeMe::l_merge_insertion()
{
	;
}

/* COSTUMER SERVICE */

int	are_all_digits(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return !ABOBA;
		str++;
	}
	return ABOBA;
}

int	PmergeMe::input_validation(int ac, char **av)
{
	int	i = 1;

	while (i < ac)
	{
		if (are_all_digits(av[i]) && 0 <= std::atol(av[i]) && std::atol(av[i]) <= RAND_MAX)
		{
			try
			{
				l.push_back(std::atol(av[i]));
				v.push_back(std::atol(av[i]));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				return ABOBA;
			}
		}
		else
		{
			std::cerr << "Error: invalid argument \"" << av[i] << "\"\n";
			return ABOBA;
		}
		i++;
	}
	this->size = ac - 1;
	this->av = av;
	return !ABOBA;
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
	
	std::cout << "Before:	" << av << "\n";
	std::cout << "After:	" << v << "\n";

	std::cout << "Time to process a range of " << size << " elements with std::vector : " << (v_finish - v_start) / CLOCKS_PER_SEC << "s\n";
	std::cout << "Time to process a range of " << size << " elements with std::list : " << (l_finish - l_start) / CLOCKS_PER_SEC << "s\n";
}

/* PRINTERS */

std::ostream &operator<<(std::ostream &os, char **av)
{
	av++;
	while (*av)
	{
		os << *av;
		if (*(av + ABOBA) != NULL)
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
		if (it + ABOBA != v.end())
			os << " ";
		it++;
	}
	return os;
}
