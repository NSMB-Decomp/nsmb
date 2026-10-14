#include "Object306.hpp"

void *Object306::create()
{
	return new Object306();
}

// 0x020dac58
ActorProfile Object306_Profile = { Object306::create, 306, 297, NULL /* TODO: 0x020d5330 */ };
