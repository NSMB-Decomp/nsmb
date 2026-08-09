#include "Object100.hpp"

void *Object100::create()
{
	return new Object100();
}

// 0x0217b708
ActorProfile Object100_Profile = { Object100::create, 100, 228, NULL /* TODO: 0x0217a6c0 */ };
