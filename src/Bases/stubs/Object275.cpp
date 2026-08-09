#include "Object275.hpp"

void *Object275::create()
{
	return new Object275();
}

// 0x02124938
ActorProfile Object275_Profile = { Object275::create, 275, 283, NULL };
