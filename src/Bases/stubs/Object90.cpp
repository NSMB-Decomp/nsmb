#include "Object90.hpp"

void *Object90::create()
{
	return new Object90();
}

// 0x0213cd18
ActorProfile Object90_Profile = { Object90::create, 90, 126, NULL /* TODO: 0x0213cbd4 */ };
