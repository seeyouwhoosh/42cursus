#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include <string>
# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;

	public:
		HumanB(const std::string& n);
		HumanB(const std::string& _name, Weapon &_weapon);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &_weapon);
};

#endif //HUMAN_B_HPP