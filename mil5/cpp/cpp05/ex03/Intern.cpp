#include "Intern.hpp"
#include <cctype>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"


Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(Intern &other)
{
	(void)other;
	return *this;
}

void	ft_strlower(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		std::tolower(str[i]);
}


AForm	*createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm	*createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	if (name.empty() || target.empty())
		return NULL;
	
	std::string	options[][2] = {
		{"robotomy", "request"},
		{"presidential", "pardon"},
		{"shrubbery", "creation"}
	};

	AForm	*(*formTypes[])(std::string) = {
		createRobotomy,
		createPresidential,
		createShrubbery
	};

	for (size_t i = 0; i < 3; i++)
	{
		if (name.find(options[i][0]) != std::string::npos && name.find(options[i][1]) != std::string::npos)
		{
			std::cout << "Intern creates a " << options[i][0] << " " << options[i][1] << " form\n";
			return formTypes[i](target);
		}
	}
	std::cerr << "Intern couldn't create form\n";
	return NULL;
}