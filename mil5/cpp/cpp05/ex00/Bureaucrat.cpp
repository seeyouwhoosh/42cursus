#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): name(name)
{
	if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
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

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char *Bureaucrat::GradeTooHighException::what() const
{
	return "This grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char *Bureaucrat::GradeTooLowException::what() const
{
	return "This grade is too low";
}

const std::string	&Bureaucrat::getName() const
{
	return this->name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	this->grade--;
}

void	Bureaucrat::decrementGrade()
{
		if (this->grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->grade++;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &burr)
{
	os << burr.getName() << ", bureaucrat grade: " << burr.getGrade();
	return os;
}
