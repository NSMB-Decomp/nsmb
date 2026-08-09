#include "Object343.hpp"

void *Object343::create()
{
	return new Object343();
}

// 0x020ffda8
ObjectProfile Object343_Profile = { Object343::create, 343, 343 };
