#pragma once
#include <algorithm>
#include <exception>
#include <vector>

class Span
{
private:
	unsigned int		N;
	std::vector<int>	v;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span	&operator=(Span &other);
	~Span();

	class FullSpanException: public std::exception
	{
	public:
		FullSpanException();
		const char *what() const throw();
	};
	class NotEnoughElementsException: public std::exception
	{
	public:
		NotEnoughElementsException();
		const char *what() const throw();
	};

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

Span::Span()
{
}

Span::~Span()
{
}
