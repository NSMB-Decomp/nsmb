#include "Object308.hpp"

void *Object308::create()
{
	return new Object308();
}

// 0x020daea0
ActorProfile Object308_Profile = { Object308::create, 308, 299, NULL /* TODO: 0x020d7340 */ };
