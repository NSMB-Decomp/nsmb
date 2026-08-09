#include "Object82.hpp"

void *Object82::create()
{
	return new Object82();
}

// 0x0218a518
ActorProfile Object82_Profile = { Object82::create, 82, 104, NULL };
