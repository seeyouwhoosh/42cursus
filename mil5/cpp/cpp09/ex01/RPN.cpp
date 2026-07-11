/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:56:17 by xwu               #+#    #+#             */
/*   Updated: 2026/07/11 13:04:25 by xwu              ###   ########.fr       */
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
	int						sign;

	while (c != expr.end())
	{
		sign = 1;
		if (*c == ' ')
		{
			++c;
			continue;
		}

		if (*c == '-' && (c + 1 != expr.end() && std::isdigit(*(c + 1))))
		{
			sign = -1;
			++c;
		}
		else if (c + 1 != expr.end() && *(c + 1) != ' ')
		{
			std::cerr << "Error: invalid token \"" << *c << *(c + 1)<< "\"\n";
			return 1;
		}

		if (std::isdigit(*c))
			s.push((*c - '0') * sign);
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
