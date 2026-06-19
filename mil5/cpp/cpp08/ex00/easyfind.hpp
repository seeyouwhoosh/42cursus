/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:49:58 by xwu               #+#    #+#             */
/*   Updated: 2026/06/19 15:49:58 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <exception>

class ValueNotFoundException: public std::exception
{
public:
	ValueNotFoundException() {};
	virtual const char *what() const throw()
	{
		return "Value not found";
	}
};

template <typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator	i;

	i = std::find(container.begin(), container.end(), n);
	if (i == container.end())
		throw ValueNotFoundException();
	return i;
}
