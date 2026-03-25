#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}
void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	size_t	i = 0;
	std::string	cmp[]= {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (; i < 4; i++)
		if (level == cmp[i])
			break ;
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			this->debug();
			std::cout << "\n";
			/* FALLTHROUGH */
		case 1:
			std::cout << "[ INFO ]\n";
			this->info();
			std::cout << "\n";
			/* FALLTHROUGH */
		case 2:
			std::cout << "[ WARNING ]\n";
			this->warning();
			std::cout << "\n";
			/* FALLTHROUGH */
		case 3:
			std::cout << "[ ERROR ]\n";
			this->error();
			std::cout << "\n";
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
