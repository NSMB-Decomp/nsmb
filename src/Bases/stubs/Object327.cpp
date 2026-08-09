#include "Object327.hpp"

void *Object327::create()
{
	return new Object327();
}

// 0x0203d320
ObjectProfile Object327_Profile = { Object327::create, 327, 327 };
