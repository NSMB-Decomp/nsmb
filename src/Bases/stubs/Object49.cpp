#include "Object49.hpp"

void *Object49::create()
{
	return new Object49();
}

// 0x02125088
ActorProfile Object49_Profile = { Object49::create, 49, 63, NULL };
