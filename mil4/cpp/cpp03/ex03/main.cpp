#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	Pepito("Pepito");

	Pepito.getMyStats();
	Pepito.whoAmI();
	Pepito.getMyStats();
	Pepito.attack("Jaimito");
	Pepito.takeDamage(99);
	Pepito.beRepaired(1);
	Pepito.highFivesGuys();
	Pepito.getMyStats();
}