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

static e_type	identify_scalar_type(std::string &s)
{
	bool	dot = 0;
	size_t	len = s.length();

	if (s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan")
		return SPECIAL;

	if ((len == 1 && !isdigit(s[0])) || \
		(len == 3 && s[0] == '\'' && s[2] == '\''))
		return CHAR;

	for (size_t i = 0; i < len; i++)
	{
		if ((s[i] == '+' || s[i] == '-') && i == 0)
			continue;
		if (s[i] == '.' && !dot)
		{
			dot = 1;
			continue;
		}
		if (!isdigit(s[i]) && !(i == len - 1 && s[i] == 'f' && dot))
			return NONE;
	}
	if (!dot)
		return INT;
	else if (dot && s[len - 1] == 'f')
		return FLOAT;
	else
		return DOUBLE;
}

void	convertChar(std::string &s)
{
	int	c;

	if (s.length() == 1)
		c = s[0];
	else
		c = s[1];

	std::cout << "char: ";
	if (!std::isprint(c))
		std::cout << "Not printable\n";
	else
	{
		std::cout << "\'" << static_cast<char>(c) << "\'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << "float: " << static_cast<float>(c) << ".0f" << "\n";
		std::cout << "double: " << static_cast<double>(c) << ".0" << "\n";
	}
}

void	ScalarConverter::convert(std::string &literal)
{
	e_type	type = identify_scalar_type(literal);
	switch (type)
	{
	case CHAR:
		convertChar(literal);
		break;
	case INT:
		atoi(literal.c_str());
		break;
	case FLOAT:
		atof(literal.c_str());
		break;
	case DOUBLE:
		atof(literal.c_str());
		break;
	default:
		std::cout << "Not a valid type\n";
		break;
	}
	return;
}

/*
https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
*/