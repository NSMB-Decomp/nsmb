#include "Object20.hpp"

void *Object20::create()
{
	return new Object20();
}

void *Object137::create()
{
	return new Object137();
}

void *Object138::create()
{
	return new Object138();
}

void *Object139::create()
{
	return new Object139();
}

void *Object140::create()
{
	return new Object140();
}

void *Object141::create()
{
	return new Object141();
}

void *Object142::create()
{
	return new Object142();
}

// 0x02170820
ActorProfile Object20_Profile = { Object20::create, 20, 27, NULL };

// 0x0217082c
ActorProfile Object137_Profile = { Object137::create, 137, 113, NULL };

// 0x021707f0
ActorProfile Object138_Profile = { Object138::create, 138, 114, NULL };

// 0x021707fc
ActorProfile Object139_Profile = { Object139::create, 139, 115, NULL };

// 0x02170814
ActorProfile Object140_Profile = { Object140::create, 140, 116, NULL };

// 0x02170838
ActorProfile Object141_Profile = { Object141::create, 141, 117, NULL };

// 0x02170808
ActorProfile Object142_Profile = { Object142::create, 142, 118, NULL };
