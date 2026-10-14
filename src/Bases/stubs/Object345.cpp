#include "Object345.hpp"

void *Object345::create()
{
	return new Object345();
}

// 0x020feb50
ObjectProfile Object345_Profile = { Object345::create, 345, 345 };
