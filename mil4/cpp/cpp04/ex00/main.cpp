#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	const WrongAnimal* meta1 = new WrongAnimal();
	const WrongAnimal* t = new WrongCat();

	std::cout << meta1->getType() << " " << std::endl;
	std::cout << t->getType() << " " << std::endl;
	t->makeSound();
	meta1->makeSound();

	delete meta1;
	delete t;
	return (0);
}
