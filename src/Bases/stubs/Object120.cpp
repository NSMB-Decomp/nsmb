#include "Object120.hpp"

void *Object120::create()
{
	return new Object120();
}

// 0x0218aef0
ActorProfile Object120_Profile = { Object120::create, 120, 139, NULL /* TODO: 0x0218ad40 */ };
