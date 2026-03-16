#include "Zombie.hpp"

int	main()
{
	int	N = 20;
	Zombie *horde = zombieHorde(N, "Pepe");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;

	horde = zombieHorde(N, "Generic Zombie");
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	
}