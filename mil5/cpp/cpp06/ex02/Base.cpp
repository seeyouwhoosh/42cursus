#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

/* ************************************************************************** */

Base	*generate(void)
{
	std::srand(std::time(0));
	int s = std::rand() % 3;
	switch (s)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C\n";
	else
		std::cout << "None\n";
}
void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch(const std::exception& e) {}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B\n";
	}
	catch(const std::exception& e) {}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C\n";
	}
	catch(const std::exception& e) {}
}