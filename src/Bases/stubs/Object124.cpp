#include "Object124.hpp"

void *Object124::create()
{
	return new Object124();
}

// 0x0218a800
ActorProfile Object124_Profile = { Object124::create, 124, 143, NULL /* TODO: 0x0218a678 */ };
