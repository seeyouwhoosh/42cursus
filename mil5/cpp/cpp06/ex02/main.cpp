#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
	std::cout << "IDENTIFICATION CHECK\n";
	A a;
	identify(a);
	B b;
	identify(b);
	C c;
	identify(c);
	Base base;
	identify(base);

	std::cout << "IDENTIFICATION POINTERS CHECK\n";
	A *ap = new A;
	identify(ap);
	delete ap;
	B *bp = new B;
	identify(bp);
	delete bp;
	C *cp = new C;
	identify(cp);
	delete cp;
	Base *basep = new Base;
	identify(basep);
	delete basep;

	std::cout << "RANDOM CHECK\n";
	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
	return 0;
}