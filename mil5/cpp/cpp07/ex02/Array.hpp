#pragma once
#include <exception>

template <typename T>
class Array
{
private:
	T		*array;
	size_t	len;
public:
	Array();
	Array(int n);
	Array(Array &other);
	Array &operator=(Array &other);
	~Array();

	class OutOfBoundsException: public std::exception
	{
	public:
		OutOfBoundsException();
		const char *what() const throw();
	};
	T		&operator[](size_t index);
	size_t	size() const;
};

#include "Array.tpp"