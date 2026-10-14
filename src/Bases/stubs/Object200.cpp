#include "Object200.hpp"

void *Object200::create()
{
	return new Object200();
}

// 0x0218efc0
ActorProfile Object200_Profile = { Object200::create, 200, 247, NULL /* TODO: 0x0218d660 */ };
