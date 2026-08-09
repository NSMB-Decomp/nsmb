#include "Object285.hpp"

void *Object285::create()
{
	return new Object285();
}

// 0x02170400
ActorProfile Object285_Profile = { Object285::create, 285, 289, NULL };
