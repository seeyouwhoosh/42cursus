#include "HumanB.hpp"

HumanB::HumanB(const std::string& _name)
{
	name = _name;
	weapon = NULL;
}

HumanB::HumanB(const std::string& _name, Weapon &_weapon)
	: name(_name), weapon(&_weapon)
{
}

HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon &_weapon)
{
	weapon = &_weapon;
}


void	HumanB::attack()
{
	std::cout << name + " attacks with their " + (*weapon).getType() + '\n';
}
