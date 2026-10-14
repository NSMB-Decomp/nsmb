#include "Object203.hpp"

void *Object203::create()
{
	return new Object203();
}

// 0x02174868
ActorProfile Object203_Profile = { Object203::create, 203, 250, NULL /* TODO: 0x021740f8 */ };
