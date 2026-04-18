#pragma once
#include <string>
#include <exception>

class Bureaucrat: public std::exception
{
private:
	const std::string	name;
	size_t				grade;
	std::string			strerr;
public:
	Bureaucrat();
	Bureaucrat(std::string name, size_t grade);
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);
	~Bureaucrat();
	
	void	GradeTooHighException();
	void	GradeTooLowException();
	
	const std::string	&getName() const;
	size_t				getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &burr);