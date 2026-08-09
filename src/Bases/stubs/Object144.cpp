#include "Object144.hpp"

void *Object144::create()
{
	return new Object144();
}

void *Object145::create()
{
	return new Object145();
}

// 0x02141ba0
ActorProfile Object144_Profile = { Object144::create, 144, 167, NULL /* TODO: 0x02140a60 */ };

// 0x02141bac
ActorProfile Object145_Profile = { Object145::create, 145, 168, NULL /* TODO: 0x02140a60 */ };
