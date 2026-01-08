#include "phonebook.hpp"

Contact::Contact()
{
	for (size_t i = 0; i < 10; i++)
		info[i] = "";
}
Contact::~Contact(){}
Phonebook::Phonebook()
{
	_slot_number = -1;
}
Phonebook::~Phonebook(){}

std::string fields[11] = {
	"Name",
	"Surname",
	"Nickname",
	"Login",
	"Postal address",
	"Email",
	"Phone number",
	"Birthdate",
	"Favourite meal",
	"Underwear color",
	"Darkest secret",
};

void	Phonebook::search_contact()
{
	for (size_t i = 0; i < 10; i++)
	{
	}
	
}

void	Phonebook::add_contact()
{
	_slot_number = (_slot_number + 1) % 8;
	if (contacts[_slot_number].info[0].compare(""))
	{
		std::cout << "The Phonebook is full! We are going to overwrite information about " + contacts[_slot_number].info[0] + " " + contacts[_slot_number].info[1] + ":\n";
	}
	for (size_t i = 0; i < 11; i++)
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
	std::cout << "\nLet's review! Here is info about " + contacts[_slot_number].info[0] + " " + contacts[_slot_number].info[1] + ":\n";
	for (size_t i = 0; i < 11; i++)
	{
		std::cout << fields[i] << ": ";
		std::cout << contacts[_slot_number].info[i] << std::endl;
	}
	std::cout << "\nThanks for tuning in!\n";
}
