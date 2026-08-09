#include "Object301.hpp"

void *Object301::create()
{
	return new Object301();
}

// 0x02141a50
ActorProfile Object301_Profile = { Object301::create, 301, 273, NULL /* TODO: 0x0213f010 */ };
