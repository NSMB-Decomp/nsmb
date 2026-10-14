#include "Object210.hpp"

void *Object210::create()
{
	return new Object210();
}

// 0x0218feec
ActorProfile Object210_Profile = { Object210::create, 210, 256, NULL /* TODO: 0x0218e264 */ };
