#include "ScalarConverter.hpp"

void	printChar(int c)
{
	std::cout << "char: ";
	if (c < '\0' || c > '~')
		std::cout << "not within ascii (input ∉ [" << 0 << ", " << 126 << "])" << "\n";
	else if (!std::isprint(c))
		std::cout << "not printable (input ∈ [" << 0 << ", " << 31 << "])" << "\n";
	else
		std::cout << "\'" << static_cast<char>(c) << "\'\n";
}

void	printSpecial(std::string &s)
{
	std::cout << "char: not within ascii (input ∉ [" << 0 << ", " << 126 << "])" << "\n";
	std::cout << "int: not a int (input ∉ [" << INT_MIN << ", " << INT_MAX << "])" << "\n";

	if (s == "-inf" || s == "+inf" || s == "nan")
	{
		std::cout << "float: " << s << "f\n";
		std::cout << "double: " << s << "\n";
	}
	else
	{
		std::cout << "float: " << s << "\n";
		std::cout << "double: ";
		for (size_t i = 0; i < s.length() - 1; i++)
			std::cout << s[i];
		std::cout << "\n";
	}
}

void	printInt(long i)
{
	std::cout << "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "not a int (input ∉ [" << INT_MIN << ", " << INT_MAX << "])" << "\n";
	else
		std::cout << static_cast<int>(i) << "\n";
}

void	printFloat(double d)
{
	double	t = 0.00001;
	bool	put_f = (d != 0 && static_cast<int>(d) == 0 ? 0 : std::abs(d - static_cast<int>(d)) < t);

	std::cout << "float: ";
	if (d < -FLT_MAX || d > FLT_MAX)
		std::cout << "not a float (input ∉ [" << -FLT_MAX << ", " << FLT_MAX << "])" << "\n";
	else
		std::cout  << std::setprecision(6) << static_cast<float>(d) << (put_f ? ".0" : "") << "f\n";
}

void	printDouble(double d)
{
	double	t = 0.0000000000001;
	bool	put_f = (d != 0 && static_cast<int>(d) == 0 ? 0 : std::abs(d - static_cast<int>(d)) < t);

	std::cout << "double: ";
	if (d < -DBL_MAX || d > DBL_MAX)
		std::cout << "not a double (input ∉ [" << -DBL_MAX << ", " << DBL_MAX << "])" << "\n";
	else
		std::cout << std::setprecision(15) << static_cast<double>(d)  << (put_f ? ".0" : "") << "\n";
}