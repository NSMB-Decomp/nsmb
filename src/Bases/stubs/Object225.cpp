#include "Object225.hpp"

void *Object225::create()
{
	return new Object225();
}

// 0x0217ec88
ActorProfile Object225_Profile = { Object225::create, 225, 188, NULL /* TODO: 0x0217eaa4 */ };
