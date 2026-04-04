#pragma once
#include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		virtual ~AAnimal() = 0;

		AAnimal &operator=(const AAnimal &other);
		virtual void	makeSound() const;
		std::string	getType() const;
};

