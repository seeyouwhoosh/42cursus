#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>
# include <cstdlib>

class Phonebook
{
	private:
	size_t	_slot_number;

	public:
	~Phonebook();
	Phonebook();

	Contact	contacts[8];

	void	search_contact();
	void	add_contact();
	int		display_contacts();
};

unsigned long	ft_stoul(std::string str);
int				allblank(std::string str);
int				allprintable(std::string str);
#endif // PHONEBOOK_HPP