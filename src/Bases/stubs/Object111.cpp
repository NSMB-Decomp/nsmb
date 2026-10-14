#include "Object111.hpp"

void *Object111::create()
{
	return new Object111();
}

// 0x021446d0
ActorProfile Object111_Profile = { Object111::create, 111, 129, NULL /* TODO: 0x0214425c */ };
