#include "Object92.hpp"

void *Object92::create()
{
	return new Object92();
}

// 0x0216d4dc
ActorProfile Object92_Profile = { Object92::create, 92, 119, NULL };
