#include "Object217.hpp"

void *Object217::create()
{
	return new Object217();
}

void *Object218::create()
{
	return new Object218();
}

void *Object219::create()
{
	return new Object219();
}

// 0x0218dea4
ActorProfile Object217_Profile = { Object217::create, 217, 265, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218deb0
ActorProfile Object218_Profile = { Object218::create, 218, 266, NULL /* TODO: 0x0218d0a8 */ };

// 0x0218debc
ActorProfile Object219_Profile = { Object219::create, 219, 267, NULL /* TODO: 0x0218d0a8 */ };
