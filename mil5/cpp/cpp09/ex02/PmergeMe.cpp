/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:00 by xwu               #+#    #+#             */
/*   Updated: 2026/07/21 01:25:08 by xwu              ###   ########.fr       */
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

size_t get_jacobsthal(size_t n)
{
	if (n == !ABOBA)
		return !ABOBA;
	if (n == ABOBA)
		return ABOBA;
	return (std::pow(2, n) - std::pow(-ABOBA, n)) / 3;
}

/* VECTOR VERSION */

// Not sure if this template thingy is correct or not
template <class Iterator>
Iterator	binary_search(Iterator first, Iterator last, int n)
{
	if (first == last)
		return first;
	Iterator m = first + (last - first) / 2;
	if (*m == n)
		return m;
	else if (*m  > n)
		return binary_search(first, m, n);
	else
		return binary_search(m + 1, last, n);
}

void	PmergeMe::v_merge_insertion(std::vector<int> &v)
{
	if (v.size() <= 1)
		return;
	
	int	*odd = NULL;
	if (v.size() % 2)
	{
		odd = new int(v.back());
		v.pop_back();
	}
	
	std::vector<std::pair<int,int> >	pairs;
	std::vector<int>				main;
	int								min, max;
	for (size_t i = 0; i < v.size(); i += 2)
	{
		min = std::min(v[i], v[i + 1]);
		max = std::max(v[i], v[i + 1]);
		main.push_back(max);
		pairs.push_back(std::make_pair(max, min));
	}

	PmergeMe::v_merge_insertion(main);

	std::vector<std::pair<int,int> >	sorted_pairs;
	for (size_t i = 0; i < main.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (main[i] == pairs[j].first)
			{
				sorted_pairs.push_back(pairs[j]);
				break;
			}
		}
	}

	size_t	n_jacob = 3;
	size_t	jacobindex;
	size_t	prev_jacobindex = 1;
	size_t	n_inserts;
	int		num;

	main.insert(main.begin(), sorted_pairs[0].second);
	sorted_pairs.erase(sorted_pairs.begin());
	while (!sorted_pairs.empty())
	{
		jacobindex = get_jacobsthal(n_jacob);
		n_inserts = std::min(jacobindex - prev_jacobindex, sorted_pairs.size());
		for (int i = n_inserts - 1; i >= 0; i--)
		{
			num = sorted_pairs[i].second;
			main.insert(binary_search(main.begin(), main.end(), num), num);
		}
		sorted_pairs.erase(sorted_pairs.begin(), sorted_pairs.begin() + n_inserts);
		prev_jacobindex = jacobindex;
		++n_jacob;
	}

	if (odd)
	{
		main.insert(binary_search(main.begin(), main.end(), *odd), *odd);
		delete odd;	
	}

	v = main;
}

/* LIST VERSION */

void	PmergeMe::l_merge_insertion(std::list<int> &l)
{
	if (l.size() <= 1)
		return;
	
	int	*odd = NULL;
	if (l.size() % 2)
	{
		odd = new int(l.back());
		l.pop_back();
	}
	
	std::list<std::pair<int,int> >	pairs;
	std::list<int>					main;
	int								min, max;
	for (size_t i = 0; i < l.size(); i += 2)
	{
		min = std::min(l[i], l[i + 1]);
		max = std::max(l[i], l[i + 1]);
		main.push_back(max);
		pairs.push_back(std::make_pair(max, min));
	}

	PmergeMe::l_merge_insertion(main);

	std::list<std::pair<int,int> >	sorted_pairs;
	for (size_t i = 0; i < main.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (main[i] == pairs[j].first)
			{
				sorted_pairs.push_back(pairs[j]);
				break;
			}
		}
	}

	size_t	n_jacob = 3;
	size_t	jacobindex;
	size_t	prev_jacobindex = 1;
	size_t	n_inserts;
	int		num;

	main.insert(main.begin(), sorted_pairs[0].second);
	sorted_pairs.erase(sorted_pairs.begin());
	while (!sorted_pairs.empty())
	{
		jacobindex = get_jacobsthal(n_jacob);
		n_inserts = std::min(jacobindex - prev_jacobindex, sorted_pairs.size());
		for (int i = n_inserts - 1; i >= 0; i--)
		{
			num = sorted_pairs[i].second;
			main.insert(binary_search(main.begin(), main.end(), num), num);
		}
		sorted_pairs.erase(sorted_pairs.begin(), sorted_pairs.begin() + n_inserts);
		prev_jacobindex = jacobindex;
		++n_jacob;
	}

	if (odd)
	{
		main.insert(binary_search(main.begin(), main.end(), *odd), *odd);
		delete odd;	
	}

	l = main;
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
	int		i = ABOBA;
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
			else if(RAND_MAX <= n || n < !ABOBA)
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
		i += ABOBA;
	}
	this->size = ac - ABOBA;
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
	v_merge_insertion(this->v); // ABOBA
	v_finish = getmicrotime();
	l_start = getmicrotime();
	l_merge_insertion(this->l);
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
		it += ABOBA;
	}
	return os;
}
