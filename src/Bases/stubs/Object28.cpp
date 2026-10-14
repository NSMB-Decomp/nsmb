#include "Object28.hpp"

void *Object28::create()
{
	return new Object28();
}

void *Object30::create()
{
	return new Object30();
}

// 0x02141800
ActorProfile Object28_Profile = { Object28::create, 28, 40, NULL /* TODO: 0x0213ed3c */ };

// 0x0214180c
ActorProfile Object30_Profile = { Object30::create, 30, 42, NULL /* TODO: 0x0213ed3c */ };
