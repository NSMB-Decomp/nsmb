#include "Object314.hpp"

void *Object314::create()
{
	return new Object314();
}

// 0x020ee2c8
ActorProfile Object314_Profile = { Object314::create, 314, 305, NULL };
