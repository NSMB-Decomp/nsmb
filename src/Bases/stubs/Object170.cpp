#include "Object170.hpp"

void *Object170::create()
{
	return new Object170();
}

// 0x02148920
ActorProfile Object170_Profile = { Object170::create, 170, 209, NULL /* TODO: 0x02147bfc */ };
