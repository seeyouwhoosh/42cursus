#include <iostream>
#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat pepito("Pepito", 2);
	Bureaucrat pepito_twin("Pepito's twin", 150);
	Bureaucrat pepito_twin2(pepito);

	pepito_twin = pepito;
	return 0;
}