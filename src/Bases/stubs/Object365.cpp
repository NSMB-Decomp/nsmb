#include "Object365.hpp"

void *Object365::create()
{
	return new Object365();
}

// 0x02119ba0
ObjectProfile Object365_Profile = { Object365::create, 365, 365 };
