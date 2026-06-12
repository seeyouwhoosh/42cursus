#include "Span.hpp"
#include <iostream>
#include <algorithm>

int main()
{
/* 	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl; */

	Span sp(100);

	for (size_t i = 0; i < 100; i++)
	{
		unsigned int n = std::rand();
		sp.addNumber(n);
		std::cout << n << "\n";
	}
	std::cout << "----------------------------------------\n";

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return (0);
}