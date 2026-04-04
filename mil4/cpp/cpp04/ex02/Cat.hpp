#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
{
private:
	Brain	*brain;

public:
	Cat();
	Cat(const Cat &other);
	~Cat();

	Cat	&operator=(const Cat &other);
	void	makeSound() const;

	void		setIdea(size_t i, std::string idea);
	std::string	&getIdea(size_t i);
};

