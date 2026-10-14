#include "Object164.hpp"

void *Object164::create()
{
	return new Object164();
}

// 0x02189650
ActorProfile Object164_Profile = { Object164::create, 164, 203, NULL /* TODO: 0x02187a88 */ };
