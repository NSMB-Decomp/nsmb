#include "Object73.hpp"

void *Object73::create()
{
	return new Object73();
}

// 0x02145388
ActorProfile Object73_Profile = { Object73::create, 73, 85, NULL /* TODO: 0x02144ee8 */ };
