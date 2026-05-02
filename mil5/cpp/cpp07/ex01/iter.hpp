#pragma once
#include <cstdlib>

template <typename T>
void	iter(T	*array, const size_t len, void (*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}
