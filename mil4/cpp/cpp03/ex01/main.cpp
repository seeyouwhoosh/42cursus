#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	Pepito("Pepito");

	Pepito.getMyStats();
	Pepito.guardGate();
	Pepito.attack("Jaimito");
	Pepito.takeDamage(99);
	for (size_t i = 0; i < 49; i++)
	{
		Pepito.beRepaired(1);
	}
	Pepito.attack("himself");
	Pepito.beRepaired(1);
	Pepito.takeDamage(100);
	Pepito.attack("himself");
	Pepito.beRepaired(1);
}
