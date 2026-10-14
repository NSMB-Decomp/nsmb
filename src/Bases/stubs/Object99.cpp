#include "Object99.hpp"

void *Object99::create()
{
	return new Object99();
}

// 0x0217b714
ActorProfile Object99_Profile = { Object99::create, 99, 227, NULL /* TODO: 0x0217a6c0 */ };
