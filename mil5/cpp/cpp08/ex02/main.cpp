/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:49:39 by xwu               #+#    #+#             */
/*   Updated: 2026/06/19 15:49:39 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

/*
int main()
{
	MutantStack<int>	mstack;

	std::cout << "PUSH TEST\n";
	mstack.push(12313);
	mstack.push(4134);

	std::cout << mstack.top() << std::endl;

	std::cout << "POP TEST\n";
	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	std::cout << "ITERATOR TEST\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(23424242);
	mstack.push(743237);
	mstack.push(43);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "Begin: " << *it << "\n";
	std::cout << "End: " << *--ite << "\n";

	++it;
	std::cout << "Increment: " << *it << "\n";

	--it;
	std::cout << "Decrement: " << *it << "\n";

	std::cout << "Printing all numbers" << "\n";
	ite++;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "Begin: " << *mstack.begin() << "\n";
	std::cout << "End: " << *--mstack.end() << "\n";
	std::cout << "Rbegin: " << *mstack.rbegin() << "\n";
	std::cout << "Rend: " << *--mstack.rend() << "\n";

	std::cout << "COPY CONSTRUCTOR TEST\n";
	std::stack<int> s(mstack);
	std::cout << s.top();
	return 0;
} 
	
/*/

int main()
{
	std::list<int>	mstack;

	std::cout << "PUSH TEST\n";
	mstack.push_back(12313);
	mstack.push_back(4134);

	std::cout << mstack.back() << std::endl;

	std::cout << "POP TEST\n";
	mstack.pop_back();

	std::cout << "Size: " << mstack.size() << std::endl;

	std::cout << "ITERATOR\n";
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(23424242);
	mstack.push_back(743237);
	mstack.push_back(43);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	std::cout << "Begin: " << *it << "\n";
	std::cout << "End: " << *--ite << "\n";

	++it;
	std::cout << "Increment: " << *it << "\n";

	--it;
	std::cout << "Decrement: " << *it << "\n";

	std::cout << "Printing all numbers" << "\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "COPY CONSTRUCTOR TEST\n";
	std::list<int> s(mstack);
	std::cout << s.back();
	return 0;
}

//*/