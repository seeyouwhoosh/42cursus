#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "A cat has appeared\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "A copy cat has appeared\n";
	*this = other;
}

Cat::~Cat()
{
	std::cout << "A cat has disappeared\n";
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "A cat has mewed\n";
}
