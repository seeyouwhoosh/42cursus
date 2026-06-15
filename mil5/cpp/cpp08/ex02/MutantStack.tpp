#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin()
{
	return this->c.cbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend()
{
	return this->c.cend();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::crbegin()
{
	return this->c.crbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::crend()
{
	return this->c.crend();
}
