#include "Object280.hpp"

void *Object280::create()
{
	return new Object280();
}

void *Object281::create()
{
	return new Object281();
}

// 0x02170290
ActorProfile Object280_Profile = { Object280::create, 280, 308, NULL /* TODO: 0x02165b54 */ };

// 0x0217029c
ActorProfile Object281_Profile = { Object281::create, 281, 311, NULL /* TODO: 0x02165b20 */ };
