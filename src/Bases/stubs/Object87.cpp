#include "Object87.hpp"

void *Object87::create()
{
	return new Object87();
}

// 0x0216d284
ActorProfile Object87_Profile = { Object87::create, 87, 110, NULL };
