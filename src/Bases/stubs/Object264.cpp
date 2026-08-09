#include "Object264.hpp"

void *Object264::create()
{
	return new Object264();
}

// 0x0218f550
ActorProfile Object264_Profile = { Object264::create, 264, 185, NULL };
