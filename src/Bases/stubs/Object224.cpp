#include "Object224.hpp"

void *Object224::create()
{
	return new Object224();
}

// 0x0218e180
ActorProfile Object224_Profile = { Object224::create, 224, 178, NULL /* TODO: 0x0218df34 */ };
