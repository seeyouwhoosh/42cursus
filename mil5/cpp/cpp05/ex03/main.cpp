#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* form = NULL;

	std::cout << "=== VALID FORMS ===" << std::endl;
	{
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *form << std::endl;

		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);

		delete form;
	}

	std::cout << "\n=== ANOTHER VALID FORM ===" << std::endl;
	{
		form = someRandomIntern.makeForm("shrubbery creation", "home");
		std::cout << *form << std::endl;

		Bureaucrat worker("Worker", 1);
		worker.signForm(*form);
		worker.executeForm(*form);

		delete form;
	}

	std::cout << "\n=== INVALID FORM ===" << std::endl;
	{
		form = someRandomIntern.makeForm("unknown form", "target");
		delete form;
	}

	return 0;
}