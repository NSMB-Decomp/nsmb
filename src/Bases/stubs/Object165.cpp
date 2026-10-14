#include "Object165.hpp"

void *Object165::create()
{
	return new Object165();
}

// 0x02125dd8
ActorProfile Object165_Profile = { Object165::create, 165, 204, NULL /* TODO: 0x020dc7c4 */ };
