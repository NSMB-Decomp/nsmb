#include "Object115.hpp"

void *Object115::create()
{
	return new Object115();
}

// 0x02146870
ActorProfile Object115_Profile = { Object115::create, 115, 133, NULL /* TODO: 0x02144dac */ };
