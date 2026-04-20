#pragma once
#include <string>
#include "AForm.hpp"

class Intern
{
private:
	
public:
	Intern();
	Intern(Intern &other);
	Intern &operator=(Intern &other);
	~Intern();

	AForm	*makeForm(std::string name, std::string target);
};

