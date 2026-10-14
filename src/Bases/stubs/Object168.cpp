#include "Object168.hpp"

void *Object168::create()
{
	return new Object168();
}

// 0x02133090
ActorProfile Object168_Profile = { Object168::create, 168, 207, NULL /* TODO: 0x02131488 */ };
