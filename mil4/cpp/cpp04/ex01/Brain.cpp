#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A brain has been generated\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "A copy brain has been generated\n";
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this == &other)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "A brain has died\n";
}
