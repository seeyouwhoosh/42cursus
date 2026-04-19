#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name): AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (file.is_open())
		file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	this->file.open(std::string(this->name).append("_shrubbery").c_str());
	try
	{
		AForm::execute(executor);
		file << "𖠰 ";
	}
	catch (const std::exception& e)
	{
		file << "↟ ";
		std::cerr << e.what() << '\n';
	}
	file.close();
}
