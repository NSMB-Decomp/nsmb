#include "Object72.hpp"

void *Object72::create()
{
	return new Object72();
}

// 0x0217067c
ActorProfile Object72_Profile = { Object72::create, 72, 84, NULL };
