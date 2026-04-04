#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Unidentified")
{
	std::cout << "An unidentified AAnimal has appeared\n";
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "An unidentified AAnimal copy has appeared\n";
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "An unidentified AAnimal has disappeared\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	this->type = other.type;
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "An unidentified AAnimal has made a sound\n";
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
