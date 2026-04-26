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
	char	chr = ScalarConverter::convert(str);
	int		z = ScalarConverter::convert(str);
	float	q = ScalarConverter::convert(str);
	double	d = ScalarConverter::convert(str);
	std::cout << typeid(chr).name() << " " << chr << "\n";
	std::cout << typeid(z).name() << " " << z << "\n";
	std::cout << typeid(q).name() << " " << q << "\n";
	std::cout << typeid(d).name() << " " << d << "\n";
	
	return 0;
}