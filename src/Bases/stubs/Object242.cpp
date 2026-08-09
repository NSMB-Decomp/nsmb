#include "Object242.hpp"

void *Object242::create()
{
	return new Object242();
}

void *Object243::create()
{
	return new Object243();
}

void *Object244::create()
{
	return new Object244();
}

void *Object245::create()
{
	return new Object245();
}

void *Object246::create()
{
	return new Object246();
}

void *Object247::create()
{
	return new Object247();
}

// 0x02171020
ActorProfile Object242_Profile = { Object242::create, 242, 96, NULL };

// 0x0217102c
ActorProfile Object243_Profile = { Object243::create, 243, 97, NULL };

// 0x02171038
ActorProfile Object244_Profile = { Object244::create, 244, 98, NULL };

// 0x02171044
ActorProfile Object245_Profile = { Object245::create, 245, 99, NULL };

// 0x02171050
ActorProfile Object246_Profile = { Object246::create, 246, 100, NULL };

// 0x0217105c
ActorProfile Object247_Profile = { Object247::create, 247, 101, NULL };
