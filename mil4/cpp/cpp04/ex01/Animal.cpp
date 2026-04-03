#include "Animal.hpp"

Animal::Animal() : type("Unidentified")
{
	std::cout << "An unidentified animal has appeared\n";
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal::~Animal()
{
	std::cout << "An unidentified animal has disappeared\n";
}

Animal &Animal::operator=(const Animal &other)
{
	this->type = other.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "An unidentified animal has made a sound\n";
}

std::string	Animal::getType() const
{
	return (this->type);
}
