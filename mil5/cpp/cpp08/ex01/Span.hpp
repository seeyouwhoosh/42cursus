/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:50:20 by xwu               #+#    #+#             */
/*   Updated: 2026/06/19 15:50:20 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <exception>
#include <vector>

class Span
{
private:
	unsigned int		N;
	std::vector<int>	v;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span	&operator=(const Span &other);
	~Span();

	class FullSpanException: public std::exception
	{
	public:
		FullSpanException();
		const char *what() const throw();
	};
	class NotEnoughElementsException: public std::exception
	{
	public:
		NotEnoughElementsException();
		const char *what() const throw();
	};

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	template <class Iterator>
	void	addNumber(Iterator begin, Iterator end)
	{
		for (Iterator it = begin; it != end ; it++)
			this->addNumber(*it);
	}
};

