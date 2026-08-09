#include "Object181.hpp"

void *Object181::create()
{
	return new Object181();
}

// 0x02189518
ActorProfile Object181_Profile = { Object181::create, 181, 220, NULL /* TODO: 0x0218737c */ };
