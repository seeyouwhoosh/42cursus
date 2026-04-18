#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade): name(name)
{
	if (grade > 150)
	{
		throw GradeTooLowException;
		return ;
	}
	if (grade < 1)
	{
		throw GradeTooHighException;
		return ;
	}
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

Bureaucrat::~Bureaucrat() {}

void	Bureaucrat::GradeTooHighException()
{
	this->strerr = "Grade is too high (maximum of 1)";
}

void	Bureaucrat::GradeTooLowException()
{
	this->strerr = "Grade is too low (maximum of 150)";
}

const std::string	&Bureaucrat::getName() const
{
	return this->name;
}

size_t	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
	{
		throw GradeTooHighException;
		return ;
	}
	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
		if (this->grade == 150)
	{
		throw GradeTooLowException;
		return ;
	}
	this->grade++;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &burr)
{
	os << burr.getName() << ", bureaucrat grade " << burr.getGrade();
	return os;
}