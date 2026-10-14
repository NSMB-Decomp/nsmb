#include "Object44.hpp"

void *Object44::create()
{
	return new Object44();
}

// 0x02175560
ActorProfile Object44_Profile = { Object44::create, 44, 58, NULL /* TODO: 0x0217307c */ };
