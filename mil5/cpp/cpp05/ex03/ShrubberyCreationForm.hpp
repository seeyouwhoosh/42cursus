#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string name);
	~ShrubberyCreationForm();

	void		execute(Bureaucrat const &executor) const;
};

