#include "Phonebook.hpp"

int main()
{
	Phonebook phonebook;
	std::string	input;
	std::string options[] = {
		"ADD",
		"SEARCH",
		"EXIT"
	};

	std::cout << "Welcome to your Phonebook!" << std::endl;
	while (1)
	{
		std::cout << "\nWhat do you want to do?\n[ADD] Add a new contact\n[SEARCH] Display all contacts\n[EXIT] Exit\n\n";
		if (!std::getline(std::cin, input))
		{
			std::cout << "OK! Bye bye!" << std::endl;
			return (0);
		}
		else if (!input.compare(options[0]))
			phonebook.add_contact();
		else if (!input.compare(options[1]))
			phonebook.search_contact();
		else if (!input.compare(options[2]))
		{
			std::cout << "OK! Bye bye!" << std::endl;
			return (0);
		}
		else
			std::cout << "S-sorry... W-what did you say?" << std::endl;
	}
}
