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
		form = someRandomIntern.makeForm("a robotomy request", "Bender");
		if (!form)
			return (delete form, 1);

		std::cout << *form << std::endl;

		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);

		delete form;
	}

	std::cout << "\n=== ANOTHER VALID FORM ===" << std::endl;
	{
		form = someRandomIntern.makeForm("a shrubbery creation", "home");
		if (!form)
			return (delete form, 1);

		std::cout << *form << std::endl;

		Bureaucrat worker("Worker", 1);
		worker.signForm(*form);
		worker.executeForm(*form);

		delete form;
	}

		std::cout << "\n=== ANOTHER VALID FORM 2 ===" << std::endl;
	{
		form = someRandomIntern.makeForm("a presidential pardon", "Pepito");
		if (!form)
			return (delete form, 1);
		
		std::cout << *form << std::endl;

		Bureaucrat presi("President", 1);
		presi.signForm(*form);
		presi.executeForm(*form);

		delete form;
	}

	std::cout << "\n=== INVALID FORM ===" << std::endl;
	{
		form = someRandomIntern.makeForm("an unknown form", "target");
		delete form;
	}

	return 0;
}