#include "Object324.hpp"

void *Object324::create()
{
	return new Object324();
}

// 0x020e9bf0
ActorProfile Object324_Profile = { Object324::create, 324, 4, NULL };
