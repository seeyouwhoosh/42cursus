#include "phonebook.hpp"

Contact::Contact()
{
	for (size_t i = 0; i < 5; i++)
		info[i] = "";
}
Contact::~Contact(){}
Phonebook::Phonebook()
{
	_slot_number = -1;
}
Phonebook::~Phonebook(){}

std::string fields[5] = {
	"Name",
	"Surname",
	"Nickname",
	"Phone number",
	"Darkest secret",
};

int	Phonebook::display_contacts()
{
	size_t	i;

	if (contacts[0].info[0].empty())
	{
		std::cout << "There are currently no contacts! Add some using the command [ADD]. Until next time!" << std::endl;
		return (-1);
	}

	std::cout << std::setw(11) << "Index|" << std::setw(11) << "Name|" << std::setw(11) << "Surname|" << std::setw(10) << "Nickname"<< std::endl;

	for (i = 0; i < 8; i++)
	{
		if (contacts[i].info[0].empty())
			break;

		std::cout << std::setw(10);
		std::cout << i << "|";
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << std::setw(10);
			if (contacts[i].info[j].length() > 9)
				std::cout << contacts[i].info[j].substr(0, 9) + "." ;
			else
				std::cout << contacts[i].info[j];
			if (j != 2)
				std::cout << "|";
			else
				std::cout << std::endl;
		}
	}
	return (i);
}


void	Phonebook::search_contact()
{
	int				j;
	std::string		temp;
	int				max;

	if ((max = display_contacts()) < 0)
		return;
	
	j = -1;
	while (1)
	{
		std::cerr << "Whose information do you want to display (insert index): ";
		if (!std::getline(std::cin, temp))
		{
			std::cout << "\nIt's fine... Bye!" << std::endl;
			exit(0);;
		}
		try
		{
			std::stoul(temp);
		}
		catch (...)
		{
			std::cerr << "Write positive numbers, geez" << std::endl;
			continue;
		}
		j = std::stoul(temp);
		if (j < 0 || j > max)
			std::cerr << "Please, put something sensible!" << std::endl;
		else
			break;
	}
	std::cout << "\nLet's review! Here is info about " + contacts[j].info[0] + " " + contacts[j].info[1] + ":\n";
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << fields[i] << ": ";
		std::cout << contacts[j].info[i] << std::endl;
	}
}

void	Phonebook::add_contact()
{
	_slot_number = (_slot_number + 1) % 8;
	if (!contacts[_slot_number].info[0].empty())
	{
		std::cout << "The Phonebook is full! We are going to overwrite information about " + contacts[_slot_number].info[0] + " " + contacts[_slot_number].info[1] + ":\n";
	}
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << fields[i] + ": ";
		if (!std::getline(std::cin, contacts[_slot_number].info[i]))
		{
			std::cout << "\nIt's fine... Bye!" << std::endl;
			exit(0);
		};
		while (contacts[_slot_number].info[i].empty())
		{
			std::cout << "\nHEY, a contact info can't be blank. You must know. Try again.\n";
			std::cout << fields[i] + ": ";
			if (!std::getline(std::cin, contacts[_slot_number].info[i]))
			{
				std::cout << "\nIt's fine... Bye for now!" << std::endl;
				exit(0);;
			}
		}
	}
	std::cout << "\nThanks for tuning in!\n";
}
