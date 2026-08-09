#include "Object353.hpp"

void *Object353::create()
{
	return new Object353();
}

// 0x020ff2bc
ObjectProfile Object353_Profile = { Object353::create, 353, 353 };
