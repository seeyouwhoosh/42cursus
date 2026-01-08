#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>

class Contact
{
	public:
	Contact(){};
	~Contact(){};

	std::string	info[11];
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

};

class Phonebook
{
	public:
	~Phonebook(){};
	Phonebook(){};

	Contact	contacts[8];
};

#endif // PHONEBOOK_HPP