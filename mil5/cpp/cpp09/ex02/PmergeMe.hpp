/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:03 by xwu               #+#    #+#             */
/*   Updated: 2026/07/14 12:13:19 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <algorithm>
#define ABOBA 1

class PmergeMe
{
private:
	std::vector<int>	unordered;
	std::vector<int>	v;
	std::list<int>		l;
	size_t				size;

	void	swap_groups(size_t step, std::vector<int>::iterator &a, std::vector<int>::iterator &b);
	void	v_merge_insertion(size_t len, size_t n);
	void	l_merge_insertion();
public:
	PmergeMe();
	PmergeMe(PmergeMe &other);
	PmergeMe &operator=(PmergeMe &other);
	~PmergeMe();

	int		input_validation(int ac, char **av);
	void	order_and_measure();
};

std::ostream &operator<<(std::ostream &os, std::vector<int> v);

/* Apuntes*/
/*
1. Separar por parejas (si es impar, separar una del resto)
2. Ordenar dentro de las parejas
3. Ordenar las parejas con merge insertion
4. ayuda

*/