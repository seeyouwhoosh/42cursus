#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	/* const AAnimal* meta = new AAnimal();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	delete meta; */
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	delete i;
	delete j;
	return (0);
}
