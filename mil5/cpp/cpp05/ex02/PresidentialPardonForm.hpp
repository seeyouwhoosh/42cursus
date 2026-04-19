#pragma once
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string name);
	~PresidentialPardonForm();

	void		execute(Bureaucrat const &executor);
};

