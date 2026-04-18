#pragma once
#include <string>

class Bureaucrat
{
private:
	const std::string	name;
	size_t				grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, size_t grade);
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(Bureaucrat &other);
	~Bureaucrat();
};
