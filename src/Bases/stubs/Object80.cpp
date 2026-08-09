#include "Object80.hpp"

void *Object80::create()
{
	return new Object80();
}

// 0x0216cec8
ActorProfile Object80_Profile = { Object80::create, 80, 95, NULL };
