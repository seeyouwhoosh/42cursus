#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "A dog has appeared\n";
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	*this = other;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "A dog has disappeared\n";
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	AAnimal::operator=(other);
	this->brain = new Brain(*other.brain);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "A dog has barked\n";
}

void	Dog::setIdea(size_t i, std::string idea)
{
	this->brain->ideas[i] = idea;
}
std::string	&Dog::getIdea(size_t i)
{
	return (this->brain->ideas[i]);
}