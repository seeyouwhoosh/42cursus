#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal	*animals[50];
	
	for (size_t i = 0; i < 50; i++)
	{
		std::cout << "\n" << i + 1 << "\n";
		if (i & 1)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();

		animals[i]->makeSound();
	}
	for (size_t i = 0; i < 50; i++)
	{
		std::cout << "\n" << i + 1 << "\n";
		delete animals[i];
	}

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
	std::cout << "\n";

	Cat	Garikoitz;

	Garikoitz = Hypatia;
	Garikoitz = Platon;

	return (0);
}
