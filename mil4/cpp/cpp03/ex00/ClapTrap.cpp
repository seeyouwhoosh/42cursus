#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name(name), hitPts(10), energyPts(10), attackDmg(0)
{
	std::cout << "A wild ClapTrap called " + name + " has appeared!\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " + name + " has perished\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
	return (*this);
}
