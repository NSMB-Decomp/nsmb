#include "Object65.hpp"

void *Object65::create()
{
	return new Object65();
}

// 0x0213f928
ActorProfile Object65_Profile = { Object65::create, 65, 79, NULL /* TODO: 0x0213effc */ };
