#include <iostream>
#include "iter.hpp"

template<typename T>
void x2(T& x) {
	x *= 2;
}

template<typename T>
void p(const T& x) {
	std::cout << x << "\n";
}

int main()
{
	std::cout << "TEST 1: INTEGERS\n";
	size_t len = 10;
	int* const a = new int[len];
	for (size_t i = 0; i < len; i++) {
		a[i] = (int)i + 1;
	}
	iter(a, len, x2);
	for (size_t i = 0; i < len; i++) {
		std::cout << a[i] << "\n";
	}
	delete[] a;

	std::cout << "TEST 2: FLOATS\n";
	float* b = new float[len];
	for (size_t i = 0; i < len; i++) {
		b[i] = (float)i + 1.5;
	}
	iter(b, len, x2);
	for (size_t i = 0; i < len; i++) {
		std::cout << b[i] << "\n";
	}

	std::cout << "TEST 3: CONSTANT NUMBERS\n";
	const int	c[] = {1, 2, 3, 4, 5, 6};
	iter(c, 6, p);
	delete[] b;
}