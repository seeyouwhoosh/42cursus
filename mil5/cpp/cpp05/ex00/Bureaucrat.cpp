#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade): name(name)
{
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{
}