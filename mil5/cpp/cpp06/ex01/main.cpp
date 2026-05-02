#include "Serializer.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

int	main()
{
	Data	*me = new Data;
	if (!me)
		return 1;
	me->name	= std::string("xwu");
	me->number	= 5;
	me->type	= 'X';

	std::cout << "Data: " << me << "\n";
	std::cout << "name: " << me->name << "\n";
	std::cout << "number: " << me->number << "\n";
	std::cout << "type: " << me->type << "\n";

	uintptr_t ptr = Serializer::serialize(me);

	std::cout << "uintptr_t: " << ptr << "\n";
	std::cout << "uintptr_t + 1: " << ptr + 1 << "\n";

	Data	*me_reconverted = Serializer::deserialize(ptr);

	std::cout << "Data: " << me_reconverted << "\n";
	std::cout << "name: " << me_reconverted->name << "\n";
	std::cout << "number: " << me_reconverted->number << "\n";
	std::cout << "type: " << me_reconverted->type << "\n";

	delete me;
}
