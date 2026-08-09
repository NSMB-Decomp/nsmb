#include "Object60.hpp"

void *Object60::create()
{
	return new Object60();
}

// 0x021416b0
ActorProfile Object60_Profile = { Object60::create, 60, 74, NULL /* TODO: 0x0213cf30 */ };
