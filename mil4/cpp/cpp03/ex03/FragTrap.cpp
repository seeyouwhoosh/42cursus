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

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name)
{
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " + this->name + " said: \"GUYS! HAVE A HIGH FIVEヾ(*^▽^*)ﾉ\n \" [Y/n]\n";
}

void FragTrap::getMyStats()
{
	std::cout << "FragTrap " + this->name + " has the following stats:\nHit Points: " << this->hitPts << "\nEnergy Points: " << this->energyPts << "\nAttack damage Points: " << this->attackDmg << "\n";
}
