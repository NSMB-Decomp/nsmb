#include "Object183.hpp"

void *Object183::create()
{
	return new Object183();
}

// 0x02188040
ActorProfile Object183_Profile = { Object183::create, 183, 222, NULL /* TODO: 0x02186bc8 */ };
