#include "Object302.hpp"

void *Object302::create()
{
	return new Object302();
}

// 0x02170084
ActorProfile Object302_Profile = { Object302::create, 302, 274, NULL /* TODO: 0x02162968 */ };
