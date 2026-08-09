#include "Object10.hpp"

void *Object10::create()
{
	return new Object10();
}

// 0x0215bb9c
ObjectProfile Object10_Profile = { Object10::create, 10, 17 };
