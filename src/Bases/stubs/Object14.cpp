#include "Object14.hpp"

void *Object14::create()
{
	return new Object14();
}

// 0x020cccc0
ObjectProfile Object14_Profile = { Object14::create, 14, 21 };
