#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);
		Form contract("Contract", 50, 25);

		std::cout << contract << "\n";

		std::cout << "\n=== SIGN TEST (FAIL) ===\n";
		intern.signForm(contract);
		std::cout << contract << "\n";

		std::cout << "\n=== SIGN TEST (SUCCESS) ===\n";
		boss.signForm(contract);
		std::cout << contract << "\n";

		std::cout << "\n=== GRADE TOO HIGH FORM ===\n";
		try
		{
			Form TooHigh("TooHigh", 0, 10);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}

		std::cout << "\n=== GRADE TOO LOW FORM ===\n";
		try
		{
			Form TooLow("TooLow", 151, 10);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}