#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				issigned;
	const int			sign_grade;
	const int			exec_grade;
public:
	Form();
	Form(const std::string name, bool issigned, const int sign_grade, const int exec_grade);
	Form(Form &other);
	Form &operator=(Form &other);
	~Form();

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

	const std::string	getName() const;
	bool				getSignedStatus() const;
	const int			getSignGrade() const;
	const int			getExecGrade() const;
	void				beSigned(Bureaucrat &burr);
};

std::ostream &operator<<(std::ostream &os, const Form &form);