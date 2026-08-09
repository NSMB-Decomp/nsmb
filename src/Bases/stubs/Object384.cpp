#include "Object384.hpp"

void *Object384::create()
{
	return new Object384();
}

// 0x0211a2ac
ObjectProfile Object384_Profile = { Object384::create, 384, 384 };
