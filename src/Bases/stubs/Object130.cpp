#include "Object130.hpp"

void *Object130::create()
{
	return new Object130();
}

// 0x021876d8
ActorProfile Object130_Profile = { Object130::create, 130, 148, NULL /* TODO: 0x0218721c */ };
