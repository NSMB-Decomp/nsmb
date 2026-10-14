#include "Object312.hpp"

void *Object312::create()
{
	return new Object312();
}

// 0x020db0b0
ActorProfile Object312_Profile = { Object312::create, 312, 303, NULL /* TODO: 0x020d8cb0 */ };
