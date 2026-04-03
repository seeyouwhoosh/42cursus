#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Jaimito("Jaimito");

	Jaimito.getMyStats();
	Jaimito.attack("himself");
	Jaimito.takeDamage(5);
	for (size_t i = 0; i < 10; i++)
	{
		Jaimito.beRepaired(1);
	}
	Jaimito.takeDamage(50);
	Jaimito.attack("himself");
}
