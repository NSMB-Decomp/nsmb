#include "Object222.hpp"

void *Object222::create()
{
	return new Object222();
}

void *Object223::create()
{
	return new Object223();
}

// 0x0218de74
ActorProfile Object222_Profile = { Object222::create, 222, 270, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218de80
ActorProfile Object223_Profile = { Object223::create, 223, 271, NULL /* TODO: 0x0218d0a8 */ };
