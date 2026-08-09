#include "Object380.hpp"

void *Object380::create()
{
	return new Object380();
}

// 0x0211b294
ObjectProfile Object380_Profile = { Object380::create, 380, 380 };
