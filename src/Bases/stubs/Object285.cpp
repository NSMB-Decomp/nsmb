#include "Object285.hpp"

void *Object285::create()
{
	return new Object285();
}

void *Object285::create2()
{
	return new Object285();
}

// 0x021703f4
ActorProfile Object286_Profile = { Object285::create2, 286, 290, NULL };

// 0x02170400
ActorProfile Object285_Profile = { Object285::create, 285, 289, NULL };
