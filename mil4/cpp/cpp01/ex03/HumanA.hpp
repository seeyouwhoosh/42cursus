#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include <string>
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
		HumanA(const std::string& _name, Weapon &_weapon);
		~HumanA();

		void	attack();
};

#endif //HUMAN_A_HPP