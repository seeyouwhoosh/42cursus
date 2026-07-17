/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:00 by xwu               #+#    #+#             */
/*   Updated: 2026/07/14 13:12:53 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iterator>

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


// No funciona
void	PmergeMe::swap_groups(size_t step, std::vector<int>::iterator &a, std::vector<int>::iterator &b)
{
	int	temp;

	while (step > 0)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		a--;
		b--;
		step--;
	}
}

void	PmergeMe::v_merge_insertion(size_t len, size_t n)
{
	size_t	step = 2 * n;
	std::vector<int>::iterator	odd;

	if (!(len % 2))
		odd = v.end() - 1;
	(void)step;
	std::vector<int>::iterator	group_1;
	std::vector<int>::iterator	group_2;
	for (size_t i = n - 1; i <= (len / 2); i += step)
	{
		group_1 = v.begin() + i;
		group_2 = v.begin() + i + n;
		std::cout << *group_1 << " " << *group_2 << "\n";
/* 		if (*group_1 > *group_2)
			swap_groups(step, group_1, group_2);
 */	}

	//PmergeMe::v_merge_insertion(this->size / step, step);

	/*
	crear operadores para comparar pairs
	mirar qué es realmente el Jacobsthal
	*/
}

/* LIST VERSION */

void	PmergeMe::l_merge_insertion()
{
	;
}

/* COSTUMER SERVICE */

template<class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val)
{
	while (first!=last)
	{
		if (*first==val)
			return first;
		++first;
	}
	return last;
}

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
	int		i = 1;
	long	n;

	while (i < ac)
	{
		if (are_all_digits(av[i]))
		{
			n = std::atol(av[i]);
			if (std::find(unordered.begin(), unordered.end(), n) != unordered.end())
			{
				std::cerr << "Error: invalid argument \"" << av[i] << "\"\n";
				return ABOBA;
			}
			else if(RAND_MAX <= n || n < 0)
			{
				std::cerr << "Error: not a negative integer \"" << av[i] << "\"\n";
				return ABOBA;
			}
			try
			{
				this->unordered.push_back(std::atol(av[i]));
				this->v.push_back(std::atol(av[i]));
				this->l.push_back(std::atol(av[i]));
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
	return !ABOBA;
}

void	PmergeMe::order_and_measure()
{
	clock_t	v_start;
	clock_t	v_finish;
	clock_t	l_start;
	clock_t	l_finish;

	v_start = clock();
	v_merge_insertion(this->size, 2);
	v_finish = clock();
	l_start = clock();
	l_merge_insertion();
	l_finish = clock();
	
	std::cout << "Before:	" << this->unordered << "\n";
	std::cout << "After:	" << this->v << "\n";

	std::cout << "Time to process a range of " << this->size << " elements with std::vector : " << (v_finish - v_start) / CLOCKS_PER_SEC << "s\n";
	std::cout << "Time to process a range of " << this->size << " elements with std::list : " << (l_finish - l_start) / CLOCKS_PER_SEC << "s\n";
}

/* PRINTERS */

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
