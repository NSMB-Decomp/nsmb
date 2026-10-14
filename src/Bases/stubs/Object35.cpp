#include "Object35.hpp"

void *Object35::create()
{
	return new Object35();
}

// 0x02152460
ActorProfile Object35_Profile = { Object35::create, 35, 48, NULL /* TODO: 0x0214e29c */ };
