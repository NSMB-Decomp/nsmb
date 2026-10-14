#include "Object240.hpp"

void *Object240::create()
{
	return new Object240();
}

// 0x02124014
ActorProfile Object240_Profile = { Object240::create, 240, 43, NULL };
