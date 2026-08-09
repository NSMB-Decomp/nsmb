#include "Object71.hpp"

void *Object71::create()
{
	return new Object71();
}

// 0x02170538
ActorProfile Object71_Profile = { Object71::create, 71, 83, NULL };
