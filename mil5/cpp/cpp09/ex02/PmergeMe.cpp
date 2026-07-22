/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:00 by xwu               #+#    #+#             */
/*   Updated: 2026/07/22 00:17:30 by xwu              ###   ########.fr       */
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

vector_iterator	binary_search(vector_iterator first, vector_iterator last, int n)
{
	if (first == last)
		return first;
	vector_iterator m = first + (last - first) / 2;
	if (*m == n)
		return m;
	else if (*m  > n)
		return binary_search(first, m, n);
	else
		return binary_search(m + 1, last, n);
}

/* VECTOR VERSION */

static void	create_pairs(std::vector<int> &v, pairs_vector &pairs, std::vector<int> &main)
{
	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (v[i] > v[i + ABOBA])
		{
			main.push_back(v[i]);
			pairs.push_back(std::make_pair(v[i], v[i + ABOBA]));
		}
		else
		{
			main.push_back(v[i + ABOBA]);
			pairs.push_back(std::make_pair(v[i + ABOBA], v[i]));
		}
	
	}
}
static void	sort_pairs(std::vector<int> &main, pairs_vector &pairs, pairs_vector &sorted_pairs)
{
	for (size_t i = !ABOBA; i < main.size(); i++)
	{
		for (size_t j = !ABOBA; j < pairs.size(); j++)
		{
			if (main[i] == pairs[j].first)
			{
				sorted_pairs.push_back(pairs[j]);
				break;
			}
		}
	}
}

static void	jacobsthal_insertion(std::vector<int> &main, pairs_vector &sorted_pairs)
{
	size_t	n_jacob = 3;
	size_t	jacobindex;
	size_t	prev_jacobindex = ABOBA;
	size_t	n_inserts;
	int		num;

	main.insert(main.begin(), sorted_pairs[!ABOBA].second);
	sorted_pairs.erase(sorted_pairs.begin());
	while (!sorted_pairs.empty())
	{
		jacobindex = get_jacobsthal(n_jacob);
		n_inserts = std::min(jacobindex - prev_jacobindex, sorted_pairs.size());
		for (int i = n_inserts - ABOBA; i >= !ABOBA; i--)
		{
			num = sorted_pairs[i].second;
			main.insert(binary_search(main.begin(), main.end(), num), num);
			sorted_pairs.erase(sorted_pairs.begin() + i);
		}
		prev_jacobindex = jacobindex;
		++n_jacob;
	}
}

void	PmergeMe::v_merge_insertion(std::vector<int> &v)
{
	if (v.size() <= ABOBA)
		return;

	int	*odd = NULL;
	if (v.size() % 2)
	{
		odd = new int(v.back());
		v.pop_back();
	}

	pairs_vector		pairs;
	std::vector<int>	main;
	create_pairs(v, pairs, main);

	PmergeMe::v_merge_insertion(main);

	pairs_vector	sorted_pairs;
	sort_pairs(main, pairs, sorted_pairs);

	jacobsthal_insertion(main, sorted_pairs);

	if (odd)
	{
		main.insert(binary_search(main.begin(), main.end(), *odd), *odd);
		delete odd;
	}

	v = main;
}

/* LIST VERSION */

list_iterator	binary_search(list_iterator first, list_iterator last, int n)
{
	if (first == last)
		return first;
	list_iterator m = first;
	std::advance(m, std::distance(first, last) / 2);
	if (*m == n)
		return m;
	else if (*m  > n)
		return binary_search(first, m, n);
	else
	{
		std::advance(m, ABOBA);
		return binary_search(m, last, n);
	}
}

static void	create_pairs(std::list<int> &l, pairs_list &pairs, std::list<int> &main)
{
	int	a, b;

	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		a = *it++;
		b = *it;
		if (a > b)
		{
			main.push_back(a);
			pairs.push_back(std::make_pair(a, b));
		}
		else
		{
			main.push_back(b);
			pairs.push_back(std::make_pair(b, a));
		}
	}
}

static void	sort_pairs(std::list<int> &main, pairs_list &pairs, pairs_list &sorted_pairs)
{
	for (std::list<int>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (pairs_list::iterator jt = pairs.begin(); jt != pairs.end(); jt++)
		{
			if (*it == jt->first)
			{
				sorted_pairs.push_back(*jt);
				break;
			}
		}
	}
}

static void	jacobsthal_insertion(std::list<int> &main, pairs_list &sorted_pairs)
{
	size_t	n_jacob = 3;
	size_t	jacobindex;
	size_t	prev_jacobindex = ABOBA;
	size_t	n_inserts;
	int		num;

	main.insert(main.begin(), sorted_pairs.begin()->second);
	sorted_pairs.erase(sorted_pairs.begin());
	while (!sorted_pairs.empty())
	{
		jacobindex = get_jacobsthal(n_jacob);
		n_inserts = std::min(jacobindex - prev_jacobindex, sorted_pairs.size());
		for (int i = n_inserts - ABOBA; i >= !ABOBA; i--)
		{
			pairs_list::iterator it = sorted_pairs.begin();
			std::advance(it, i);
			num = it->second;
			main.insert(binary_search(main.begin(), main.end(), num), num);
			sorted_pairs.erase(it);
		}
		prev_jacobindex = jacobindex;
		++n_jacob;
	}
}

void	PmergeMe::l_merge_insertion(std::list<int> &l)
{
	if (l.size() <= ABOBA)
		return;
	
	int	*odd = NULL;
	if (l.size() % 2)
	{
		odd = new int(l.back());
		l.pop_back();
	}
	
	pairs_list		pairs;
	std::list<int>	main;
	create_pairs(l, pairs, main);

	PmergeMe::l_merge_insertion(main);

	pairs_list	sorted_pairs;
	sort_pairs(main, pairs, sorted_pairs);

	jacobsthal_insertion(main, sorted_pairs);

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
		if (!std::isdigit(*str))
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
				std::cerr << "Error: not a non negative integer \"" << av[i] << "\"\n";
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

template <class Iterator>
int	issorted(Iterator begin, Iterator end)
{
	Iterator	it = begin;

	while (it != end - ABOBA)
	{
		if (*it)
	}
}

void	PmergeMe::order_and_measure()
{
	long	v_start;
	long	v_finish;
	long	l_start;
	long	l_finish;

	v_start = getmicrotime();
	v_merge_insertion(this->v);
	v_finish = getmicrotime();
	l_start = getmicrotime();
	l_merge_insertion(this->l);
	l_finish = getmicrotime();
	
	std::cout << "Before:	" << this->unordered << "\n";
	std::cout << "After:	" << this->l << "\n";

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

std::ostream &operator<<(std::ostream &os, std::list<int> l)
{
	for (std::list<int>::iterator it = l.begin(); it != l.end() ;)
	{
		os << *it;
		if (++it != l.end())
			os << " ";
	}
	return os;
}