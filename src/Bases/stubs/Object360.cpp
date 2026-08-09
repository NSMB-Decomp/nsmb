#include "Object360.hpp"

void *Object360::create()
{
	return new Object360();
}

// 0x0211a01c
ObjectProfile Object360_Profile = { Object360::create, 360, 360 };
