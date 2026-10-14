#include "Object70.hpp"

void *Object70::create()
{
	return new Object70();
}

// 0x02175818
ActorProfile Object70_Profile = { Object70::create, 70, 82, NULL /* TODO: 0x021751d8 */ };
