#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain	*brain;

public:
	Cat();
	Cat(const Cat &other);
	~Cat();

	Animal	&operator=(const Animal &other);
	void	makeSound() const;

	void		setIdea(size_t i, std::string idea);
	std::string	&getIdea(size_t i);
	Brain		*getBrain() const;
};

