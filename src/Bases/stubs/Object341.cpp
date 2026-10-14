#include "Object341.hpp"

void *Object341::create()
{
	return new Object341();
}

// 0x020ff560
ObjectProfile Object341_Profile = { Object341::create, 341, 341 };
