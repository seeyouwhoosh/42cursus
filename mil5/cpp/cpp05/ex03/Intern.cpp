#include "Intern.hpp"
#include <cctype>

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern &other) {}

Intern &Intern::operator=(Intern &other) {}

void	ft_strlower(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::tolower(str[i]);
}

std::string	options[][2] = 
{
	{"robotomy", "request"},
	{"presidential", "pardon"},
	{"shrubbery", "creation"}
}

AForm	*makeForm(std::string name, std::string target)
{
	if (name.empty() || target.empty())
		return NULL;
}