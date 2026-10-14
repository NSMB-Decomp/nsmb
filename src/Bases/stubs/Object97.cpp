#include "Object97.hpp"

void *Object97::create()
{
	return new Object97();
}

// 0x02133d08
ActorProfile Object97_Profile = { Object97::create, 97, 253, NULL };
