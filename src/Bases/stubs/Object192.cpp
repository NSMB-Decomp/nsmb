#include "Object192.hpp"

void *Object192::create()
{
	return new Object192();
}

// 0x02147ff0
ActorProfile Object192_Profile = { Object192::create, 192, 238, NULL /* TODO: 0x02147ec4 */ };
