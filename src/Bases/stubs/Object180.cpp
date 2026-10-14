#include "Object180.hpp"

void *Object180::create()
{
	return new Object180();
}

// 0x021893f8
ActorProfile Object180_Profile = { Object180::create, 180, 219, NULL /* TODO: 0x02187060 */ };
