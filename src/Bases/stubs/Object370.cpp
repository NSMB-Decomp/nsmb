#include "Object370.hpp"

void *Object370::create()
{
	return new Object370();
}

// 0x0211ab44
ObjectProfile Object370_Profile = { Object370::create, 370, 370 };
