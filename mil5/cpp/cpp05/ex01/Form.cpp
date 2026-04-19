#include "Form.hpp"

Form::Form() : name("Default"), issigned(false), sign_grade(150), exec_grade(150) {}

Form::Form(const std::string name, bool issigned, const int sign_grade, const int exec_grade) : name(name), issigned(issigned), sign_grade(sign_grade), exec_grade(exec_grade) {}

Form::Form(Form &other): name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
	*this = other;
}

Form &Form::operator=(Form &other)
{
	this->issigned = other.issigned;
	return *this;
}

Form::~Form() {}

Form::GradeTooHighException::GradeTooHighException() {}

const char *Form::GradeTooHighException::what() const throw()
{
	return "This grade is too high";
}

Form::GradeTooLowException::GradeTooLowException() {}

const char *Form::GradeTooLowException::what() const throw()
{
	return "This grade is too low";
}

const std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getSignedStatus() const
{
	return this->issigned;
}

const int	Form::getSignGrade() const
{
	return this->sign_grade;
}

const int	Form::getExecGrade() const
{
	return this->exec_grade;
}

void	Form::beSigned(Bureaucrat &burr)
{
	if (burr.getGrade() <= 150)
		this->issigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << ", signed status: " << form.getSignedStatus() << ", sign grade " << form.getSignGrade() << ", execution grade: " << form.getExecGrade();
	return os;
}