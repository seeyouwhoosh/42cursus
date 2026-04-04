#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "A cat has appeared\n";
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "A copy cat has appeared\n";
	*this = other;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "A cat has disappeared\n";
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	delete this->brain;
	AAnimal::operator=(other);
	this->brain = new Brain(*other.brain);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "A cat has mewed\n";
}

void	Cat::setIdea(size_t i, std::string idea)
{
	this->brain->ideas[i] = idea;
}
std::string	&Cat::getIdea(size_t i)
{
	return (this->brain->ideas[i]);
}