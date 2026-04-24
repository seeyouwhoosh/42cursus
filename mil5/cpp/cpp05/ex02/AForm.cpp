#include "AForm.hpp"

AForm::AForm() : name("Default"), issigned(false), sign_grade(150), exec_grade(150) {}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) :
name(name),
issigned(false),
sign_grade(sign_grade > 150 ? throw GradeTooLowException() : (sign_grade < 1 ? throw GradeTooHighException() : sign_grade)),
exec_grade(exec_grade > 150 ? throw GradeTooLowException() : (exec_grade < 1 ? throw GradeTooHighException() : exec_grade))
{}

AForm::AForm(AForm &other): name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	*this = other;
}

AForm &AForm::operator=(AForm &other)
{
	this->issigned = other.issigned;
	return *this;
}

AForm::~AForm() {}

AForm::GradeTooHighException::GradeTooHighException() {}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

AForm::GradeTooLowException::GradeTooLowException() {}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

AForm::FormNotSignedException::FormNotSignedException() {}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form not signed";
}

const std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getSignedStatus() const
{
	return this->issigned;
}

int	AForm::getSignGrade() const
{
	return this->sign_grade;
}

int	AForm::getExecGrade() const
{
	return this->exec_grade;
}

void	AForm::beSigned(const Bureaucrat &burr)
{
	if (burr.getGrade() <= this->sign_grade)
		this->issigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::isexecutable(Bureaucrat const &executor) const
{
	if (!this->issigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->exec_grade)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName() << ", AForm signed status: " << form.getSignedStatus() << ", sign grade " << form.getSignGrade() << ", execution grade: " << form.getExecGrade();
	return os;
}