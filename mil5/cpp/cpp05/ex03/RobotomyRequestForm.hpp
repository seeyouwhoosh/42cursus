#pragma once
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string name);
	~RobotomyRequestForm();

	class NotLuckyEnough: public std::exception
	{
	public:
		NotLuckyEnough();
		const char *what() const throw();
	};

	void		execute(Bureaucrat const &executor) const;
};

