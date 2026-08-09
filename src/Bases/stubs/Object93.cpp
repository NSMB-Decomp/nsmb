#include "Object93.hpp"

void *Object93::create()
{
	return new Object93();
}

// 0x021469b0
ActorProfile Object93_Profile = { Object93::create, 93, 121, NULL /* TODO: 0x021462c8 */ };
