#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPts = 100;
	this->energyPts = 50;
	this->attackDmg = 20;
	std::cout << "A ferocious default ScavTrap named has appeared!\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->hitPts = 100;
	this->energyPts = 50;
	this->attackDmg = 20;
	std::cout << "A ferocious ScavTrap named " + name + " has appeared!\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " + name + " has perished ferociously!\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name)
{
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPts == 0)
	{
		std::cout << "ScavTrap " + this->name + " is already K.O. and can't do anything else!\n";
		return ;
	}
	if (this->energyPts > 0)
	{
		std::cout << "ScavTrap " + this->name + " attacks ferociusly " + target + ", causing " << this->attackDmg << " points of damage!\n";
		this->energyPts--;
	}
	else
	{
		std::cout << "ScavTrap " + this->name + " wants to attack ferociusly " + target + " to deal " << this->attackDmg << " points of damage but has no energy points left!\n";
	}
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " + this->name + " is guarding ferociusly the gate!\n";
}

void ScavTrap::getMyStats()
{
	std::cout << "ScavTrap " + this->name + " has the following stats:\nHit Points: " << this->hitPts << "\nEnergy Points: " << this->energyPts << "\nAttack damage Points: " << this->attackDmg << "\n";
}