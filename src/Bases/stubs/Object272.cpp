#include "Object272.hpp"

void *Object272::create()
{
	return new Object272();
}

void *Object272::create2()
{
	return new Object272();
}

// 0x021247f4
ActorProfile Object273_Profile = { Object272::create2, 273, 281, NULL };

// 0x02124800
ActorProfile Object272_Profile = { Object272::create, 272, 280, NULL };
