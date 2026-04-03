#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("Default"), hitPts(10), energyPts(10), attackDmg(0)
{
	std::cout << "A wild default ClapTrap called has appeared!\n";
}

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
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPts == 0)
	{
		std::cout << "ClapTrap " + this->name + " is already K.O. and can't do anything else!\n";
		return ;
	}
	if (this->energyPts > 0)
	{
		std::cout << "ClapTrap " + this->name + " attacks " + target + ", causing " << this->attackDmg << " points of damage!\n";
		this->energyPts--;
	}
	else
	{
		std::cout << "ClapTrap " + this->name + " wants to attack " + target + " to deal " << this->attackDmg << " points of damage but has no energy points left!\n";
		this->energyPts = 0;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPts > 0)
	{
		std::cout << "ClapTrap " + this->name + " received " << amount << " points of damage!\n";
		if (this->hitPts <= amount)
			this->hitPts = 0;
		else
			this->hitPts -= amount;	}
	else
	{
		std::cout << "ClapTrap " + this->name + " is already K.O. and can't received any more damage!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPts == 0)
	{
		std::cout << "ClapTrap " + this->name + " is already K.O. and can't do anything else!\n";
		return ;
	}
	if (this->energyPts > 0)
	{
		std::cout << "ClapTrap " + this->name + " has repaired itself and has recovered " << amount << " hit points!\n";
		this->hitPts += amount;
		this->energyPts--;
	}
	else
	{
		std::cout << "ClapTrap " + this->name + " wants to repair itself, but has no energy points left!\n";
	}
}

void ClapTrap::getMyStats()
{
	std::cout << "ClapTrap " + this->name + " has the following stats:\nHit Points: " << this->hitPts << "\nEnergy Points: " << this->energyPts << "\nAttack damage Points: " << this->attackDmg << "\n";
}