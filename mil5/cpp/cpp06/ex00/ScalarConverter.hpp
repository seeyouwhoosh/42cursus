#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <float.h>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &other);
public:
	ScalarConverter &operator=(ScalarConverter &other);
	~ScalarConverter();

	static void	convert(std::string &literal);
};

enum e_type {
	NONE,
	SPECIAL,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

/* ************************************************************************** */

void	printChar(int c);
void	printSpecial(std::string &s);
void	printInt(long i);
void	printFloat(double d);
void	printDouble(double d);