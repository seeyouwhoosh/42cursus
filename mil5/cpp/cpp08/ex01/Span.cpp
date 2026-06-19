#include "Span.hpp"
#include <iostream>

Span::Span() : N(0) {}

Span::~Span() {}

Span::Span(unsigned int N) : N(N), v() {}

Span::Span(const Span &other)
{
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	this->N = other.N;
	this->v = other.v;
	return *this;
}

Span::FullSpanException::FullSpanException() {}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

Span::NotEnoughElementsException::NotEnoughElementsException() {}

const char *Span::NotEnoughElementsException::what() const throw()
{
	return "Not enough elements to compute";
}

void	Span::addNumber(int n)
{
	if (N == v.size())
		throw FullSpanException();
	v.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end ; it++)
	{
		this->addNumber(*it);
	}
}

unsigned int	Span::shortestSpan()
{
	if (N < 2 || v.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int>::iterator begin = v.begin();
	std::vector<int>::iterator end = v.end();

	std::sort(begin, end);

	unsigned int	span;
	unsigned int	first_shortest = *(begin + 1) - *begin++;
	while (begin != end - 1)
	{
		span = *(begin + 1) - *begin;
		if (span < first_shortest)
			first_shortest = span;
		begin++;
	}
	return first_shortest;
}

unsigned int	Span::longestSpan()
{
	if (N < 2 || v.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int>::iterator begin = v.begin();
	std::vector<int>::iterator end = v.end();

	std::sort(begin, end);

	return v.back() - *begin;
}
