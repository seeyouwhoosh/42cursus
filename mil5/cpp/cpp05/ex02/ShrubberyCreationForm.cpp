#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name): AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	file;
	file.open(std::string(this->name).append("_shrubbery").c_str(), std::ios::app);
	try
	{
		AForm::isexecutable(executor);
		file << "𖠰";
	}
	catch (const std::exception& e)
	{
		file << "↟";
		throw e;
	}
	file.close();
}
