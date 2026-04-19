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
		intern.executeForm(shrub); // debería fallar (grade bajo)

		boss.signForm(shrub);
		boss.executeForm(shrub);   // debería funcionar


		std::cout << "\n=== ROBOTOMY TEST ===\n";
		RobotomyRequestForm robot("Bender");

		boss.signForm(robot);

		for (int i = 0; i < 5; i++)
			boss.executeForm(robot); // 50% success


		std::cout << "\n=== PRESIDENTIAL TEST ===\n";
		PresidentialPardonForm president("Arthur Dent");

		intern.signForm(president); // debería fallar
		boss.signForm(president);

		intern.executeForm(president); // debería fallar
		boss.executeForm(president);   // debería funcionar


		std::cout << "\n=== NOT SIGNED TEST ===\n";
		ShrubberyCreationForm notSigned("garden");
		boss.executeForm(notSigned); // debería lanzar excepción


		std::cout << "\n=== GRADE TOO LOW TEST ===\n";
		Bureaucrat mid("Mid", 50);
		PresidentialPardonForm hard("Someone");

		mid.signForm(hard);      // debería fallar
		mid.executeForm(hard);   // debería fallar
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}