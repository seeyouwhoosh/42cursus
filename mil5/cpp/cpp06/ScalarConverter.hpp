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

	static <algún tipo>convert(std::string &literal);
};

