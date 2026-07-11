/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:10:03 by xwu               #+#    #+#             */
/*   Updated: 2026/07/11 19:35:58 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <list>
#include <ctime>
#include <iostream>

class PmergeMe
{
private:
	char				**av;
	std::vector<int>	v;
	std::list<int>		l;
	size_t				size;

	void	v_merge_insertion();
	void	l_merge_insertion();
public:
	PmergeMe();
	PmergeMe(PmergeMe &other);
	PmergeMe &operator=(PmergeMe &other);
	~PmergeMe();

	int		input_validation(char **av);
	void	order_and_measure();
};

std::ostream &operator<<(std::ostream &os, char **av);
std::ostream &operator<<(std::ostream &os, std::vector<int> v);
std::ostream &operator<<(std::ostream &os, std::list<int> l);