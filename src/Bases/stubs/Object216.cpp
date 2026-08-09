#include "Object216.hpp"

void *Object216::create()
{
	return new Object216();
}

// 0x0218dec8
ActorProfile Object216_Profile = { Object216::create, 216, 264, NULL /* TODO: 0x0218d0a8 */ };
