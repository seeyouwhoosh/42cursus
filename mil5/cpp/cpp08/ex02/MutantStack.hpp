#pragma once
#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack: public std::stack<T>
{
private:

public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator		begin();
	iterator		end();
	iterator		rbegin();
	iterator		rend();
	const_iterator	cbegin();
	const_iterator	cend();
	const_iterator	crbegin();
	const_iterator	crend();
};

#include "MutantStack.tpp"