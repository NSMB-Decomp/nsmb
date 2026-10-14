#include "Object69.hpp"

void *Object69::create()
{
	return new Object69();
}

// 0x0216e16c
ActorProfile Object69_Profile = { Object69::create, 69, 81, NULL /* TODO: 0x0215e2c4 */ };
