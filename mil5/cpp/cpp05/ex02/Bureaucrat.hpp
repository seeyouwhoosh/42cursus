#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);
	~Bureaucrat();
	
	class GradeTooHighException: public std::exception
	{
	public:
		GradeTooHighException();
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
	public:
		GradeTooLowException();
		const char *what() const throw();
	};
	
	const std::string	&getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm &form);
	void				executeForm(const AForm &form) const;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &burr);