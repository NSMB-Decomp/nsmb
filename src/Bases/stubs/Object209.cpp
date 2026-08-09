#include "Object209.hpp"

void *Object209::create()
{
	return new Object209();
}

// 0x02182578
ActorProfile Object209_Profile = { Object209::create, 209, 275, NULL /* TODO: 0x02181bbc */ };
