#pragma once
#include <string>
#include <exception>

class Bureaucrat
{
private:
	const std::string	name;
	unsigned int		grade;
	std::string			strerr;
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
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
	unsigned int				getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &burr);