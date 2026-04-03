#pragma once
#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &other);
		virtual void	makeSound() const;
		std::string	getType() const;
};

