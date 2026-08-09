#include "Object220.hpp"

void *Object220::create()
{
	return new Object220();
}

// 0x0218de98
ActorProfile Object220_Profile = { Object220::create, 220, 268, NULL /* TODO: 0x0218d0a8 */ };
