#include "Object286.hpp"

void *Object286::create()
{
	return new Object286();
}

// 0x021703f4
ActorProfile Object286_Profile = { Object286::create, 286, 290, NULL };
