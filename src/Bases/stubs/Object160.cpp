#include "Object160.hpp"

void *Object160::create()
{
	return new Object160();
}

// 0x0216e2b0
ActorProfile Object160_Profile = { Object160::create, 160, 6, NULL /* TODO: 0x0215f974 */ };
