#include "Object50.hpp"

void *Object50::create()
{
	return new Object50();
}

// 0x0217f75c
ActorProfile Object50_Profile = { Object50::create, 50, 64, NULL /* TODO: 0x0217e9e8 */ };
