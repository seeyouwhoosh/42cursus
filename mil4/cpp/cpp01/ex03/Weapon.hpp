#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(const std::string& _type);
		~Weapon();

		std::string	getType();
		void		setType(const std::string& newtype);
};

#endif //WEAPON_HPP