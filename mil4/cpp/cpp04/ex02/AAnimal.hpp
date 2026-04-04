#pragma once
#include <iostream>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &other);
		virtual void	makeSound() const = 0;
		std::string	getType() const;
};

