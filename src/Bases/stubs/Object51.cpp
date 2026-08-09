#include "Object51.hpp"

void *Object51::create()
{
	return new Object51();
}

void *Object52::create()
{
	return new Object52();
}

void *Object53::create()
{
	return new Object53();
}

// 0x0217f738
ActorProfile Object51_Profile = { Object51::create, 51, 65, NULL /* TODO: 0x0217e9e8 */ };

// 0x0217f750
ActorProfile Object52_Profile = { Object52::create, 52, 66, NULL /* TODO: 0x0217e9e8 */ };

// 0x0217f744
ActorProfile Object53_Profile = { Object53::create, 53, 67, NULL /* TODO: 0x0217e9e8 */ };
