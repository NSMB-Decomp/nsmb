#include "Object315.hpp"

void *Object315::create()
{
	return new Object315();
}

// 0x020ccd30
ActorProfile Object315_Profile = { Object315::create, 315, 306, NULL };
