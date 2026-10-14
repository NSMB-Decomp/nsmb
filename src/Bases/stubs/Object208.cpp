#include "Object208.hpp"

void *Object208::create()
{
	return new Object208();
}

// 0x02188208
ActorProfile Object208_Profile = { Object208::create, 208, 255, NULL /* TODO: 0x02187e58 */ };
