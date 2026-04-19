#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat pepito("Pepito", 1);
	std::cout << pepito << "\n";

	/*
	try
	{
		pepito.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
/*/
	try
	{
		for (; 150 > pepito.getGrade();)
		{
			pepito.decrementGrade();
		}
		
		std::cout << pepito << "\n";

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
//*/

/*
	try
	{
		Bureaucrat pepito_twin("Pepito's twin", -1);
		std::cout << pepito_twin << "\n";

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
/*/
	try
	{
		Bureaucrat pepito_twin("Pepito's twin", 151);
		std::cout << pepito << "\n";

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
//*/

	return 0;
}