#include "Object162.hpp"

void *Object162::create()
{
	return new Object162();
}

void *Object163::create()
{
	return new Object163();
}

// 0x02125a4c
ActorProfile Object162_Profile = { Object162::create, 162, 201, NULL /* TODO: 0x020db4c0 */ };

// 0x02125a58
ActorProfile Object163_Profile = { Object163::create, 163, 202, NULL /* TODO: 0x020db4c0 */ };
