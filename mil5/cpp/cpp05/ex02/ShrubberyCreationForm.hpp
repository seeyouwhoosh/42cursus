#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
	std::ofstream	file;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string name);
	~ShrubberyCreationForm();

	void		execute(Bureaucrat const &executor);
};

