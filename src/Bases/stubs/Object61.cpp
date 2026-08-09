#include "Object61.hpp"

void *Object61::create()
{
	return new Object61();
}

// 0x0217b4c0
ActorProfile Object61_Profile = { Object61::create, 61, 75, NULL /* TODO: 0x0217b1a4 */ };
