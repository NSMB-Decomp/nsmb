#include "Object215.hpp"

void *Object215::create()
{
	return new Object215();
}

// 0x0218fd88
ActorProfile Object215_Profile = { Object215::create, 215, 263, NULL /* TODO: 0x0218d2ec */ };
