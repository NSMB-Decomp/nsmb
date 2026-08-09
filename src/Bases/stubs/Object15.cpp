#include "Object15.hpp"

void *Object15::create()
{
	return new Object15();
}

// 0x0215b5c0
ObjectProfile Object15_Profile = { Object15::create, 15, 22 };
