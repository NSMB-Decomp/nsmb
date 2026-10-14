#include "Object40.hpp"

void *Object40::create()
{
	return new Object40();
}

void *Object123::create()
{
	return new Object123();
}

// 0x021526c0
ActorProfile Object40_Profile = { Object40::create, 40, 54, NULL /* TODO: 0x021516f0 */ };

// 0x021526cc
ActorProfile Object123_Profile = { Object123::create, 123, 142, NULL /* TODO: 0x021516f0 */ };
