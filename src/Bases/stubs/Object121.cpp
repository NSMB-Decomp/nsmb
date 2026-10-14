#include "Object121.hpp"

void *Object121::create()
{
	return new Object121();
}

// 0x02170130
ActorProfile Object121_Profile = { Object121::create, 121, 140, NULL /* TODO: 0x021634c8 */ };
