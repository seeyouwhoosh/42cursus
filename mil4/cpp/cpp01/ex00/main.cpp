#include "Zombie.hpp"

int	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

std::string	itostring(int n)
{
	std::string	str;
	int			sign;

	sign = 0;
	if (n == 0)
		return (std::string("0"));
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	while (n)
	{
		str = (char)(n % 10 + '0') + str;
		n /= 10;
	}
	if (sign)
		str = '-' + str;
	return (str);
}

int	main()
{
	Zombie	mother("Mother of all zombies");
	Zombie	eternal_servants[5] = {Zombie("Pepito"), Zombie("Jaimito"), Zombie("Juanito"), Zombie("Mateo"), Zombie("Zucchini")};
	Zombie	**deployed_zombies = new Zombie*[5];

	// Forever zombies
	mother.announce();
	for (size_t i = 0; i < 5; i++)
		eternal_servants[i].announce();
	
	// Temporary zombies
	for (size_t i = 0; i < 5; i++)
	{
		deployed_zombies[i] = newZombie("Deployed zombie " + itostring(i + 1));
		(*deployed_zombies[i]).announce();
		delete deployed_zombies[i];
	}
	delete[] deployed_zombies;

	// Forever zombies again
	for (size_t i = 0; i < 5; i++)
		eternal_servants[i].announce();
}