#include "Object350.hpp"

void *Object350::create()
{
	return new Object350();
}

// 0x02100000
ObjectProfile Object350_Profile = { Object350::create, 350, 350 };
