#include "Object91.hpp"

void *Object91::create()
{
	return new Object91();
}

// 0x02143770
ActorProfile Object91_Profile = { Object91::create, 91, 127, NULL /* TODO: 0x02143500 */ };
