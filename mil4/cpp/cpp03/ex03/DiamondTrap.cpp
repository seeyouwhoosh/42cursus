#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	this->hitPts = 100;
	this->energyPts = 50;
	this->attackDmg = 20;
	std::cout << "A ferocious and cheerful default DiamondTrap named has appeared!\n";
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	this->name = name;
	this->hitPts = FragTrap::hitPts;
	this->energyPts = ScavTrap::energyPts;
	this->attackDmg = FragTrap::attackDmg;
	std::cout << "A ferocious and cheerful DiamondTrap named " + name + " has appeared!\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " + this->name + " has perished ferocious and cheerfully!\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.name), FragTrap(other.name), ScavTrap(other.name)
{
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " + this->name + " has " + ClapTrap::name + " as her ClapTrap name\n";
}
void DiamondTrap::getMyStats()
{
	std::cout << "DiamondTrap " + this->name + " has the following stats:\nHit Points: " << this->hitPts << "\nEnergy Points: " << this->energyPts << "\nAttack damage Points: " << this->attackDmg << "\n";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}