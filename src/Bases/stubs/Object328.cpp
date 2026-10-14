#include "Object328.hpp"

void *Object328::create()
{
	return new Object328();
}

// 0x021388c4
ActorProfile Object328_Profile = { Object328::create, 328, 328, NULL };
