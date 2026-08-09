#include "Object213.hpp"

void *Object213::create()
{
	return new Object213();
}

// 0x0218e0b0
ActorProfile Object213_Profile = { Object213::create, 213, 259, NULL /* TODO: 0x0218ddf0 */ };
