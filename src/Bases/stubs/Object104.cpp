#include "Object104.hpp"

void *Object104::create()
{
	return new Object104();
}

// 0x0218e1f0
ActorProfile Object104_Profile = { Object104::create, 104, 225, NULL };
