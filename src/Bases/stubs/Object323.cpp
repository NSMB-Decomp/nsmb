#include "Object323.hpp"

void *Object323::create()
{
	return new Object323();
}

// 0x020daadc
ActorProfile Object323_Profile = { Object323::create, 323, 3, NULL };
