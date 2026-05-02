#pragma once
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer();
	Serializer(Serializer &other);
public:
	Serializer &operator=(Serializer &other);
	virtual ~Serializer() = 0;

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

