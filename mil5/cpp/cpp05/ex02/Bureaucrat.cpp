#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(150)
{
	if (grade > 150)
	{
		throw GradeTooLowException();
		return ;
	}
	if (grade < 1)
	{
		throw GradeTooHighException();
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
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "This grade is too high";
}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "This grade is too low";
}

const std::string	&Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't signed " << form.getName() << " because " << e.what() << "\n";
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn't executed " << form.getName() << " because " << e.what() << "\n";
	}
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &burr)
{
	os << burr.getName() << ", bureaucrat grade: " << burr.getGrade();
	return os;
}
