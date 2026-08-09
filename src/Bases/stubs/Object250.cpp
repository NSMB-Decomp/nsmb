#include "Object250.hpp"

void *Object250::create()
{
	return new Object250();
}

// 0x02189478
ActorProfile Object250_Profile = { Object250::create, 250, 106, NULL /* TODO: 0x02186414 */ };
