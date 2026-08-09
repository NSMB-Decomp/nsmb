#include "Object12.hpp"

void *Object12::create()
{
	return new Object12();
}

// 0x020e9b88
ObjectProfile Object12_Profile = { Object12::create, 12, 19 };
