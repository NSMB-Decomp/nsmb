#include "Object221.hpp"

void *Object221::create()
{
	return new Object221();
}

// 0x0218de8c
ActorProfile Object221_Profile = { Object221::create, 221, 269, NULL /* TODO: 0x0218d0a8 */ };
