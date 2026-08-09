#include "Object274.hpp"

void *Object274::create()
{
	return new Object274();
}

void *Object274::create2()
{
	return new Object274();
}

void *Object274::create3()
{
	return new Object274();
}

void *Object274::create4()
{
	return new Object274();
}

// 0x02124920
ActorProfile Object284_Profile = { Object274::create4, 284, 288, NULL };

// 0x0212492c
ActorProfile Object283_Profile = { Object274::create3, 283, 287, NULL };

// 0x02124938
ActorProfile Object275_Profile = { Object274::create2, 275, 283, NULL };

// 0x02124944
ActorProfile Object274_Profile = { Object274::create, 274, 282, NULL };
