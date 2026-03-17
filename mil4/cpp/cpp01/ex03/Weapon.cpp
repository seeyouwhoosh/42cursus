#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(const std::string& _type)
{
	type = _type;
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(const std::string &newtype)
{
	type = newtype;
}
