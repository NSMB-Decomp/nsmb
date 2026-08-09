#include "Object23.hpp"

void *Object23::create()
{
	return new Object23();
}

void *Object24::create()
{
	return new Object24();
}

void *Object25::create()
{
	return new Object25();
}

void *Object26::create()
{
	return new Object26();
}

// 0x021439c8
ActorProfile Object23_Profile = { Object23::create, 23, 31, NULL /* TODO: 0x02143678 */ };

// 0x021439d4
ActorProfile Object24_Profile = { Object24::create, 24, 32, NULL /* TODO: 0x02143678 */ };

// 0x021439e0
ActorProfile Object25_Profile = { Object25::create, 25, 33, NULL /* TODO: 0x02143678 */ };

// 0x021439ec
ActorProfile Object26_Profile = { Object26::create, 26, 34, NULL /* TODO: 0x02143678 */ };
