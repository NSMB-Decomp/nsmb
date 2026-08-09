#include "Object58.hpp"

void *Object58::create()
{
	return new Object58();
}

// 0x02151c38
ActorProfile Object58_Profile = { Object58::create, 58, 72, NULL /* TODO: 0x021474d0 */ };
