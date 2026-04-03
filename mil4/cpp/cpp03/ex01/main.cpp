#include "ScavTrap.hpp"
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

	ScavTrap	Pepito("Pepito");
	Pepito.guardGate();
	Pepito.attack("Jaimito");
	Pepito.takeDamage(50);
	Pepito.takeDamage(50);
	Pepito.takeDamage(50);
	for (size_t i = 0; i < 50; i++)
	{
		Pepito.beRepaired(1);
	}
	Pepito.attack("himself");
}