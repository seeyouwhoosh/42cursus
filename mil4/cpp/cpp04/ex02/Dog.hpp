#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
private:
	Brain	*brain;

public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog &operator=(const Dog &other);
	void	makeSound() const;

	void		setIdea(size_t i, std::string idea);
	std::string	&getIdea(size_t i);
};

