#include "Object326.hpp"

void *Object326::create()
{
	return new Object326();
}

// 0x020ceb24
ActorProfile Object326_Profile = { Object326::create, 326, 326, NULL };
