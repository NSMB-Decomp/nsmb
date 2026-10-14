#include "Object355.hpp"

void *Object355::create()
{
	return new Object355();
}

// 0x02100c00
ObjectProfile Object355_Profile = { Object355::create, 355, 355 };
