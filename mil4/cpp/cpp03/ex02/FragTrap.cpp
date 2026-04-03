#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPts = 100;
	this->energyPts = 100;
	this->attackDmg = 30;
	std::cout << "A cheerful default FragTrap named has appeared!\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->hitPts = 100;
	this->energyPts = 100;
	this->attackDmg = 30;
	std::cout << "A cheerful FragTrap named " + name + " has appeared!\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " + name + " has perished cheerfully!\n";
}

FragTrap::FragTrap(const FragTrap &other)
{
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::string	answer;
	std::cout << "FragTrap " + this->name + " said: \"GUYS! Can I have a high five? (*'▽'*)ﾉ\" [Y/n]\n";
	std::cin >> answer;
	if (answer == "y" || answer == "Y")
		std::cout << "YAY, HAVE A HIGH FIVEヾ(*^▽^*)ﾉ\n";
	else
		std::cout << "Ermmm, what? I guess not (*\'ᆺ\'*)ﾉ\n";
}

