#pragma once
#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
private:

public:
	MutantStack<T>::iterator		begin();
	MutantStack<T>::iterator		end();
	MutantStack<T>::iterator		rbegin();
	MutantStack<T>::iterator		rend();
	MutantStack<T>::const_iterator	cbegin();
	MutantStack<T>::const_iterator	cend();
	MutantStack<T>::const_iterator	crbegin();
	MutantStack<T>::const_iterator	crend();
};

template <typename T>
std::ostream	&operator<<(std::ostream &os, const MutantStack<T> &mstack);

/*
FUNCIONES IMPLEMENTADAs
(constructor)	Construct stack (public member function)
empty	Test whether container is empty (public member function)
size	Return size (public member function)
top	Access next element (public member function)
push	Insert element (public member function)
emplace	Construct and insert element (public member function)
pop	Remove top element (public member function)
swap	Swap contents (public member function)

Non-member function overloads
relational operators	Relational operators for stack (function)
swap (stack)	Exchange contents of stacks (public member function)
*/
#include "MutantStack.tpp"