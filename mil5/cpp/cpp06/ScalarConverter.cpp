#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	(void)other;
	return *this;
}

/* ************************************************************************** */

static double	single_case(char lit)
{
	if (!std::isprint(lit))
	{
		std::cerr << "Non-displayable character detected. Aborting\n";
		return 0;
	}
	if (std::isdigit(lit))
		return lit - '0';
	else
		return lit;
}

static short	identify_scalar_type(std::string &s)
{
	bool	dot = 0;

	if (s == "-inff" || s == "+inff" || s == "nanf")
		return LIT_FLOAT;
	if (s == "-inf" || s == "+inf" || s == "nan")
		return LIT_DOUBLE;
	if (!isdigit(s[0]) && (s[0] != '+' || s[0] != '-'))
		return NONE;
	for (size_t i = 1; i < s.length(); i++)
	{
		if (s[i] == '.' && !dot)
		{
			dot = 1;
			continue;
		}
		if (!isdigit(s[i]) && dot)
			return NONE;
	}
	if (!dot)
		return INT;
	else
		return DOUBLE;
}

double	ScalarConverter::convert(std::string &literal)
{
	if (literal.length() == 1)
		return single_case(literal[0]);

	short	type = identify_scalar_type(literal);
	switch (type)
	{
	case NONE:
		std::cout << "Not a number\n";
		return 0;
	case INT:
		return atoi(literal.c_str());
	case FLOAT:
		return atof(literal.c_str());
	case DOUBLE:
		return atof(literal.c_str());
	default:
		break;
	}
	return INFINITY;
}

/*
https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
*/