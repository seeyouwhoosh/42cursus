#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), len(0) {}

template <typename T>
Array<T>::Array(int n) : array(new T[n]), len(n) {}

template <typename T>
Array<T>::Array(Array &other) : array(new T[other.len]), len(other.len)
{
	for (size_t i = 0; i < other.len; i++)
		this->array[i] = other.array[i];
}

template <typename T>
Array<T>::~Array()
{
	if (this->array)
		delete[] this->array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array &other)
{
	if (this == &other)
		return (*this);
	delete[] this->array;
	this->len = other.len;
	this->array = new T[this->len];
	for (size_t i = 0; i < other.len; i++)
		this->array[i] = other.array[i];
}

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException() {}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "index out of bounds";
}

template <typename T>
T	&Array<T>::operator[](size_t index)
{
	if (index >= this->len)
		throw OutOfBoundsException();
	return this->array[index];
}

template <typename T>
size_t	Array<T>::size() const
{
	return (this->len);
}
