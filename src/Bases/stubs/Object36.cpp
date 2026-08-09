#include "Object36.hpp"

void *Object36::create()
{
	return new Object36();
}

// 0x021320a0
ActorProfile Object36_Profile = { Object36::create, 36, 49, NULL /* TODO: 0x02130864 */ };
