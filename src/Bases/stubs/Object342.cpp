#include "Object342.hpp"

void *Object342::create()
{
	return new Object342();
}

// 0x020ffbb0
ObjectProfile Object342_Profile = { Object342::create, 342, 342 };
