#include "Object110.hpp"

void *Object110::create()
{
	return new Object110();
}

// 0x02179420
ActorProfile Object110_Profile = { Object110::create, 110, 128, NULL /* TODO: 0x02178ea8 */ };
