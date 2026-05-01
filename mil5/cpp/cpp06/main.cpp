#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong number of arguments\n";
		return 1;
	}
	std::string	str = av[1];

	ScalarConverter::convert(str);
	
	return 0;
}