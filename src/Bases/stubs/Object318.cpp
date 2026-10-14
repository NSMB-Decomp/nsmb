#include "Object318.hpp"

void *Object318::create()
{
	return new Object318();
}

// 0x020e58d0
ActorProfile Object318_Profile = { Object318::create, 318, 1, NULL /* TODO: 0x020ccd78 */ };
