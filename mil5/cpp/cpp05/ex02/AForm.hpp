#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string	name;
	bool				issigned;
	const int			sign_grade;
	const int			exec_grade;
public:
	AForm();
	AForm(const std::string name, const int sign_grade, const int exec_grade);
	AForm(AForm &other);
	AForm &operator=(AForm &other);
	~AForm();

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
	class FormNotSignedException: public std::exception
	{
	public:
		FormNotSignedException();
		const char *what() const throw();
	};

	const std::string	getName() const;
	bool				getSignedStatus() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(const Bureaucrat &burr);
	void		execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);