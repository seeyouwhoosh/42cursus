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
	if (!contacts[0].info[0].compare(""))
	{
		std::cout << "There are currently no contacts! Add some using the command [ADD]. Until next time!" << std::endl;
		return (-1);
	}

	std::cout << std::setw(11) << "Index|" << std::setw(11) << "Name|" << std::setw(11) << "Surname|" << std::setw(10) << "Nickname"<< std::endl;

	for (size_t i = 0; i < 8; i++)
	{
		if (!contacts[i].info[0].compare(""))
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
	return (0);
}


void	Phonebook::search_contact()
{
	int				j;
	std::string		temp;

	if (display_contacts())
		return;
	
	j = -1; // this part doesn't work yet
	while (j <= 0)
	{
		std::getline(std::cin, temp);
		try
		{
			j = std::stoul(temp);
		}
		catch (...)
		{
			std::cerr << "Write numbers, geez" << std::endl;
		}
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
	if (contacts[_slot_number].info[0].compare(""))
	{
		std::cout << "The Phonebook is full! We are going to overwrite information about " + contacts[_slot_number].info[0] + " " + contacts[_slot_number].info[1] + ":\n";
	}
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << fields[i] + ": ";
		std::getline(std::cin, contacts[_slot_number].info[i]);
		while (!contacts[_slot_number].info[i].compare(""))
		{
			std::cout << "HEY, a contact info can't be blank. You must know. Try again.\n";
			std::cout << fields[i] + ": ";
			std::getline(std::cin, contacts[_slot_number].info[i]);
		}
	}
	
	std::cout << "\nThanks for tuning in!\n";
}
