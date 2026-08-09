#include "Object29.hpp"

void *Object29::create()
{
	return new Object29();
}

// 0x02176770
ActorProfile Object29_Profile = { Object29::create, 29, 41, NULL /* TODO: 0x021765f0 */ };
