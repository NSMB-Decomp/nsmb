#include "Object199.hpp"

void *Object199::create()
{
	return new Object199();
}

// 0x02190034
ActorProfile Object199_Profile = { Object199::create, 199, 246, NULL };
