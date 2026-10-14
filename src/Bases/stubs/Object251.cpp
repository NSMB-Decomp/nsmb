#include "Object251.hpp"

void *Object251::create()
{
	return new Object251();
}

void *Object252::create()
{
	return new Object252();
}

void *Object253::create()
{
	return new Object253();
}

// 0x0216d9ac
ActorProfile Object251_Profile = { Object251::create, 251, 105, NULL };

// 0x0216d9b8
ActorProfile Object252_Profile = { Object252::create, 252, 107, NULL };

// 0x0216d9c4
ActorProfile Object253_Profile = { Object253::create, 253, 108, NULL };
