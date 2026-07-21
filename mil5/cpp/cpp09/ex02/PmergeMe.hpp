/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:03 by xwu               #+#    #+#             */
/*   Updated: 2026/07/21 01:24:13 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <list>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <algorithm>
#include <sys/time.h>
#include <cmath>
#define ABOBA 1
typedef std::vector<std::pair<int,int> > pairs_vector;
typedef std::list<std::pair<int,int> > pairs_list;

class PmergeMe
{
private:
	std::vector<int>	unordered;
	std::vector<int>	v;
	std::list<int>		l;
	size_t				size;

public:
	PmergeMe();
	PmergeMe(PmergeMe &other);
	PmergeMe &operator=(PmergeMe &other);
	~PmergeMe();

	void	v_merge_insertion(std::vector<int> &v);
	void	l_merge_insertion(std::list<int> &l);
	int		input_validation(int ac, char **av);
	void	order_and_measure();
};

std::ostream &operator<<(std::ostream &os, std::vector<int> v);
