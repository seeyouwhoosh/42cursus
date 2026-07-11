/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:56:17 by xwu               #+#    #+#             */
/*   Updated: 2026/07/11 12:49:01 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN &other)
{
	(void)other;
}

RPN::ZeroDivisionException::ZeroDivisionException() {}
const char	*RPN::ZeroDivisionException::what() const throw()
{
	return "division by zero";
}

RPN::InvalidOperation::InvalidOperation() {}
const char	*RPN::InvalidOperation::what() const throw()
{
	return "invalid operation";
}

RPN	&RPN::operator=(RPN &other)
{
	(void)other;
	return (*this);
}

int	RPN::do_operation(char c)
{
	int	a, b;
	if (s.empty())
		throw InvalidOperation();
	b = s.top();
	s.pop();
	if (s.empty())
		throw InvalidOperation();
	a = s.top();
	s.pop();

	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
		if (b == 0)
			throw ZeroDivisionException();
		return a / b;
	case '*':
		return a * b;
	default:
		break;
	}
	return 0;
}

int	RPN::calculate(std::string expr)
{
	std::string::iterator	c = expr.begin();
	std::string				operators("+-/*");
	int						result;

	while (c != expr.end())
	{
		if (*c == ' ')
		{
			++c;
			continue;
		}
		if (std::isdigit(*c))
			s.push(*c - '0');
		else if (operators.find(*c) != std::string::npos)
		{
			try
			{
				s.push(do_operation(*c));
			}
			catch (const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
				return 1;
			}
		}
		else
		{
			std::cerr << "Error: invalid character \"" << *c << "\"\n";
			return 1;
		}
		++c;
	}
	result = s.top();
	s.pop();
	if (!s.empty())
	{
		std::cerr << "Error: not enough operators" << "\n";
		return 1;
	}
	std::cout << result << "\n";
	return 0;
}
