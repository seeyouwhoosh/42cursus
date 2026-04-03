#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "A dog has appeared\n";
}

Dog::Dog(const Dog &other) : Animal()
{
	*this = other;
}

Dog::~Dog()
{
	std::cout << "A dog has disappeared\n";
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "A dog has barked\n";
}