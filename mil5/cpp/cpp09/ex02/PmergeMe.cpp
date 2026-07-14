/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:00 by xwu               #+#    #+#             */
/*   Updated: 2026/07/14 12:18:12 by xwu              ###   ########.fr       */
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

void	PmergeMe::v_merge_insertion(std::vector<int> unordered)
{
	std::vector<int>	main;
	std::vector<int>	sub;
	std::pair<std::vector<int> *, std::vector<int> *>	p(&main, &sub);

	int	*odd = NULL;
	if (this->size % 2)
		odd = &*(this->v.end() - 1);
	
	size_t	i = 0;
	int	min, max;
	while (i < this->size / 2)
	{
		main.push_back(std::max(this->v[i], this->v[i + 1]));
		sub.push_back(std::min(this->v[i], this->v[i + 1]));
		i += 2;;
	}

	PmergeMe::v_merge_insertion(main);

	
	;
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
	while (first!=last
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
				unordered.push_back(std::atol(av[i]));
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
	v_merge_insertion();
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
