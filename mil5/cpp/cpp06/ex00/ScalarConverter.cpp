#include "ScalarConverter.hpp"
#include <sstream>

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

	printChar(c);
	printInt(c);
	printFloat(c);
	printDouble(c);
}

void	convertInt(std::string &s)
{
	std::string a;

	try
	{
		a = s.substr(s.find_first_not_of('0'));
	}
	catch (std::exception& e)
	{
		a = "0";
	}
	int	i = std::atol(a.c_str());

	std::string number;
	std::stringstream strstream;
	strstream << i;
	strstream >> number;

	if (number != a)
	{
		std::cout << "Conversion not possible because of int overflow\n";
		return;
	}
	printChar(i);
	printInt(i);
	printFloat(i);
	printDouble(i);
}

void	convertFloat(std::string &s)
{
	double	d = std::atof(s.c_str());
	double	t = 0.00001;
	bool	put_f = (d != 0 && static_cast<int>(d) == 0 ? 0 : std::abs(d - static_cast<int>(d)) < t);

	printChar(d);
	printInt(d);
	printFloat(d);
	std::cout << "double: " << static_cast<double>(d) << std::setprecision(15) << (put_f ? ".0" : "") << "\n";
}

void	convertDouble(std::string &s)
{
	double	d = std::atof(s.c_str());

	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}

void	ScalarConverter::convert(std::string &literal)
{
	e_type	type = identify_scalar_type(literal);
	switch (type)
	{
	case SPECIAL:
		printSpecial(literal);
		break;
	case CHAR:
		convertChar(literal);
		break;
	case INT:
		convertInt(literal);
		break;
	case FLOAT:
		convertFloat(literal);
		break;
	case DOUBLE:
		convertDouble(literal);
		break;
	default:
		std::cout << "Not a valid type\n";
		break;
	}
	return;
}
