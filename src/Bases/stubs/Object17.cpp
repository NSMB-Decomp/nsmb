#include "Object17.hpp"

void *Object17::create()
{
	return new Object17();
}

// 0x020cc620
ObjectProfile Object17_Profile = { Object17::create, 17, 24 };
