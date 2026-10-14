#include "Object86.hpp"

void *Object86::create()
{
	return new Object86();
}

// 0x0216dd40
ActorProfile Object86_Profile = { Object86::create, 86, 109, NULL };
