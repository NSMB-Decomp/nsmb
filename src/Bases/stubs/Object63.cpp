#include "Object63.hpp"

void *Object63::create()
{
	return new Object63();
}

// 0x0217d810
ActorProfile Object63_Profile = { Object63::create, 63, 77, NULL /* TODO: 0x0217bf9c */ };
