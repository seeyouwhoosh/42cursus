#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(const std::string& n)
{
	name = n;
}

void	Zombie::setName(const std::string& n)
{
	name = n;
}


Zombie::~Zombie()
{
	std::cout << name + " has returned to eternal sleep\n";
}

void	Zombie::announce(void)
{
	std::cout << name + ": BraiiiiiiinnnzzzZ...\n";
}
