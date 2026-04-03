#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		size_t		hitPts;
		size_t		energyPts;
		size_t		attackDmg;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &other);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void getMyStats();
};
