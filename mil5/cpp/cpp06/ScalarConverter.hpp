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

	static double	convert(std::string &literal);
};

enum scalar_types {
	NONE,
	INT,
	FLOAT,
	DOUBLE,
	LIT_FLOAT,
	LIT_DOUBLE,
};
