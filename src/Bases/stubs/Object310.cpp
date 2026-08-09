#include "Object310.hpp"

void *Object310::create()
{
	return new Object310();
}

// 0x020dafd0
ActorProfile Object310_Profile = { Object310::create, 310, 301, NULL /* TODO: 0x020d84e4 */ };
