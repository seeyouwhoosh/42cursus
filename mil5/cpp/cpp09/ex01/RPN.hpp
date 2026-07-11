/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:56:20 by xwu               #+#    #+#             */
/*   Updated: 2026/07/11 12:47:52 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stack>
#include <iostream>
#include <exception>

class RPN
{
private:
	std::stack<int>	s;

	int	do_operation(char c);
public:
	RPN();
	RPN(RPN &other);
	RPN	&operator=(RPN &other);
	~RPN();

	class ZeroDivisionException: public std::exception
	{
	public:
		ZeroDivisionException();
		const char	*what() const throw();
	};
	class InvalidOperation: public std::exception
	{
	public:
		InvalidOperation();
		const char	*what() const throw();
	};
	
	int	calculate(std::string expr);
};


