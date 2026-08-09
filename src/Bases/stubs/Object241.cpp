#include "Object241.hpp"

void *Object241::create()
{
	return new Object241();
}

// 0x021245a8
ActorProfile Object241_Profile = { Object241::create, 241, 277, NULL };
