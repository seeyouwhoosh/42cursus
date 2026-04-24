#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Default", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string name): AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		AForm::isexecutable(executor);
		std::cout << this->name << " has been pardoned by Zaphod Beeblebrox\n";
	}
	catch (const std::exception& e)
	{
		std::cout << this->name << " has NOT been pardoned by Zaphod Beeblebrox because ";
		std::cerr << e.what() << "\n";
		throw e;
	}
}