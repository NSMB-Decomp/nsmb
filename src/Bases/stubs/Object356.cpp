#include "Object356.hpp"

void *Object356::create()
{
	return new Object356();
}

// 0x02100938
ObjectProfile Object356_Profile = { Object356::create, 356, 356 };
