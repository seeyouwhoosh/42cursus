#pragma once
#include <string>

class ScalarConverter
{
private:
	
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter &other);
	ScalarConverter &operator=(ScalarConverter &other);
	virtual ~ScalarConverter() = 0;

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
