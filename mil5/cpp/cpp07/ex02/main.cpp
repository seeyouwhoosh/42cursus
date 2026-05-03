#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#define MAX_VAL 750

int main(int, char**)
{
	std::cout << "1. Instatiating an Array class of ints of " << MAX_VAL << " elements\n";
	Array<int> numbers(MAX_VAL);
	std::cout << "2. Creating an int array of " << MAX_VAL << " elements\n";
	int* mirror = new int[MAX_VAL];
	
	std::cout << "3. Filling both arrays with random numbers\n";
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "4. Testing copy constructor and operator = override\n";
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (&tmp[i] == &numbers[i])
		{
			std::cerr << "shallow copy detected!" << std::endl;
			return 1;
		}
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (&test[i] == &tmp[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (&test[i] == &numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	}

	std::cout << "5. Checking differences between Array class of ints and array of ints\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	std::cout << "6. Testing exceptions (should throw exception)\n";
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "7. Testing changing values within range (should not throw exception)\n";

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}