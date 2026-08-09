#include "Object6.hpp"

void *Object6::create()
{
	return new Object6();
}

// 0x0215bdec
ActorProfile Object6_Profile = { Object6::create, 6, 14, NULL /* TODO: 0x021589e0 */ };
