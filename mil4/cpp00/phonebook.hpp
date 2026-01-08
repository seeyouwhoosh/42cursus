#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>

class Contact
{
	public:
	Contact();
	~Contact();

	std::string	info[11];
};

class Phonebook
{
	private:
	size_t	_slot_number;

	public:
	~Phonebook();
	Phonebook();

	Contact	contacts[8];

	void search_contact();
	void add_contact();
};

#endif // PHONEBOOK_HPP