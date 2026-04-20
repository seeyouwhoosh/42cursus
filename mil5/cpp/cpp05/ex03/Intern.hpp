#pragma once
#include <string>
#include "AForm.hpp"
#include <exception>

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

