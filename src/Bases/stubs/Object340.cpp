#include "Object340.hpp"

void *Object340::create()
{
	return new Object340();
}

// 0x020ff76c
ObjectProfile Object340_Profile = { Object340::create, 340, 340 };
