#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		std::cout << "\n=== SHRUBBERY TEST ===\n";
		ShrubberyCreationForm shrub("home");

		std::cout << shrub << "\n";
		intern.signForm(shrub);
		intern.executeForm(shrub);

		boss.signForm(shrub);
		boss.executeForm(shrub);

		ShrubberyCreationForm notSigned("garden");
		boss.executeForm(notSigned);

		std::cout << "\n=== ROBOTOMY TEST ===\n";
		RobotomyRequestForm robot("Bender");

		boss.signForm(robot);

		for (int i = 0; i < 10; i++)
			boss.executeForm(robot);


		std::cout << "\n=== PRESIDENTIAL TEST ===\n";
		PresidentialPardonForm president("Potatoes");

		intern.signForm(president);
		boss.signForm(president);

		intern.executeForm(president); // debería fallar
		boss.executeForm(president);   // debería funcionar
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}