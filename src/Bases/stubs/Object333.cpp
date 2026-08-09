#include "Object333.hpp"

void *Object333::create()
{
	return new Object333();
}

// 0x02138a28
ObjectProfile Object333_Profile = { Object333::create, 333, 333 };
