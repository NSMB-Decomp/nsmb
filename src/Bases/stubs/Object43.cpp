#include "Object43.hpp"

void *Object43::create()
{
	return new Object43();
}

// 0x02137458
ActorProfile Object43_Profile = { Object43::create, 43, 57, NULL /* TODO: 0x02135160 */ };
