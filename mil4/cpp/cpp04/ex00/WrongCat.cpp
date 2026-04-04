#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "A disturbing cat has appeared\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "A disturbing copy cat has appeared\n";
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "A disturbing cat has disappeared\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type = other.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "A disturbing cat has meooooooooooowed\n";
}
