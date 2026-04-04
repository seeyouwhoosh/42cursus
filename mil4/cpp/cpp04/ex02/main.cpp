#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal* meta = new Animal();
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	delete meta;

	std::cout << "\n";
	Dog *doggo = new Dog();
	doggo->setIdea(0, "I am a dog");
	Dog doggy = *doggo;
	delete doggo;

	std::cout << "doggy idea: " << doggy.getIdea(0) + "\n";
	std::cout << "\n";
	Dog doggyo(doggy);

	doggyo.setIdea(0, "I am a very original dog");
	std::cout << "doggy idea: " + doggy.getIdea(0) + "\n";
	std::cout << "doggyo idea: " + doggyo.getIdea(0) + "\n";

	std::cout << "\n";
	Cat *Aristotle = new Cat();
	Aristotle->setIdea(0, "I am a Cat");
	Cat Platon = *Aristotle;
	delete Aristotle;

	std::cout << "Platon idea: " << Platon.getIdea(0) + "\n";
	std::cout << "\n";
	Cat Hypatia(Platon);

	Hypatia.setIdea(0, "I am a very original Cat");
	std::cout << "Platon idea: " + Platon.getIdea(0) + "\n";
	std::cout << "Hypatia idea: " + Hypatia.getIdea(0) + "\n";
	return (0);
}
