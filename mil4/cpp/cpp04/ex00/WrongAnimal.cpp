#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unidentified")
{
	std::cout << "A disturbing unidentified animal has appeared\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An disturbing unidentified animal has disappeared\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	this->type = other.type;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "An disturbing unidentified animal made a disturbing sound\n";
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
