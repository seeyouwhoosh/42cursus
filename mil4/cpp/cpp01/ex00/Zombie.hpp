#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>
# include <memory>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(const std::string& n);
		~Zombie();

		void	announce(void);
};

Zombie	*newZombie(const std::string& name);
void	randomChump(const std::string& name);

#endif //ZOMBIE_HPP