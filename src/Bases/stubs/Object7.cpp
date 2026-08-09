#include "Object7.hpp"

void *Object7::create()
{
	return new Object7();
}

// 0x020e5820
ObjectProfile Object7_Profile = { Object7::create, 7, 15 };
