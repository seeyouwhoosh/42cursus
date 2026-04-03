#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Jaimito("Jaimito");

	Jaimito.attack("himself");
	Jaimito.takeDamage(5);
	Jaimito.takeDamage(5);
	Jaimito.takeDamage(5);
	for (size_t i = 0; i < 10; i++)
	{
		Jaimito.beRepaired(1);
	}
	Jaimito.attack("himself");
}
