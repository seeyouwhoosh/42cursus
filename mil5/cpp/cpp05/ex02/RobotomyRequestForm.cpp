#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string name): AForm(name, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::NotLuckyEnough::NotLuckyEnough() {}

const char *RobotomyRequestForm::NotLuckyEnough::what() const throw()
{
	return "not lucky enough";
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{

	try
	{
		AForm::isexecutable(executor);
		if (rand() % 2)
			throw NotLuckyEnough();
		std::cout << "Brrrrr, " << this->name << " has been robotomized successfully\n";
	}
	catch (const std::exception& e)
	{
		std::cout << this->name << "'s robotomy has failed because ";
		std::cerr << e.what() << "\n";
		throw e;
	}
}