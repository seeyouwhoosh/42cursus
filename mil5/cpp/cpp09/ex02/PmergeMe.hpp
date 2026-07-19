/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:03 by xwu               #+#    #+#             */
/*   Updated: 2026/07/19 17:46:16 by xwu              ###   ########.fr       */
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
	void	l_merge_insertion();
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