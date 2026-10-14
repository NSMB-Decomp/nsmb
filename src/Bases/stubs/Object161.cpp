#include "Object161.hpp"

void *Object161::create()
{
	return new Object161();
}

// 0x02125904
ActorProfile Object161_Profile = { Object161::create, 161, 200, NULL /* TODO: 0x020db4c0 */ };
