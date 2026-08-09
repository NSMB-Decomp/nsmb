#include "Object262.hpp"

void *Object262::create()
{
	return new Object262();
}

// 0x02152238
ActorProfile Object262_Profile = { Object262::create, 262, 35, NULL /* TODO: 0x0214bbf8 */ };
