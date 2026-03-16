#include "Phonebook.hpp"

int	allblank(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return (0);
	}
	return (1);
}

int	allprintable(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isprint(str[i]))
			return (0);
	}
	return (1);
}

unsigned long	ft_stoul(std::string str)
{
	int				i;
	unsigned long	number;

	i = 0;
	number = 0;
	while (std::isspace(str[i]))
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	if (!std::isdigit(str[i]))
		return (-1);
	while (std::isdigit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}
