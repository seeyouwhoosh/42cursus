/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:00 by xwu               #+#    #+#             */
/*   Updated: 2026/07/18 13:42:51 by xwu              ###   ########.fr       */
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

void	PmergeMe::swap_groups(size_t size, size_t a, size_t b)
{
	while (size > 0)
	{
		std::swap(this->v[a], this->v[b]);
		a--;
		b--;
		size--;
	}
}

void	PmergeMe::v_merge_insertion(size_t n)
{
	size_t	step = 2 * n;
	size_t	group_1;
	size_t	group_2;
	std::vector<size_t>	main;
	std::vector<size_t>	pend;
	for (size_t i = 0; i + step <= this->size; i += step)
	{
		group_1 = i + n - 1;
		group_2 = i + step - 1;
		std::cout << this->v[group_1] << " " << this->v[group_2] << "\n";
		if (this->v[group_1] > this->v[group_2])
			swap_groups(n, group_1, group_2);
		main.push_back(group_2);
		pend.push_back(group_1);
	}

	if (step >= this->size)
		return;
	PmergeMe::v_merge_insertion(step);

	/*
	insertar con jacobsthal
	*/

	// Not finished
	if ((this->size / n) % 2)
	{
		stray_group = ((this->size / n) - 1)
	}
	
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

long getmicrotime()
{
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	return current_time.tv_sec * (int)1e6 + current_time.tv_usec;
}

#include <unistd.h>
void	PmergeMe::order_and_measure()
{
	long	v_start;
	long	v_finish;
	long	l_start;
	long	l_finish;

	v_start = getmicrotime();
	v_merge_insertion(2);
	v_finish = getmicrotime();
	l_start = getmicrotime();
	l_merge_insertion();
	l_finish = getmicrotime();
	
	std::cout << "Before:	" << this->unordered << "\n";
	std::cout << "After:	" << this->v << "\n";

	std::cout << "Time to process a range of " << this->size << " elements with std::vector : " << (v_finish - v_start) << "µs\n";
	std::cout << "Time to process a range of " << this->size << " elements with std::list : " << (l_finish - l_start) << "µs\n";
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
