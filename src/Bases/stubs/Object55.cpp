#include "Object55.hpp"

void *Object55::create()
{
	return new Object55();
}

void *Object56::create()
{
	return new Object56();
}

// 0x0213f450
ActorProfile Object55_Profile = { Object55::create, 55, 69, NULL /* TODO: 0x0213d768 */ };

// 0x0213f45c
ActorProfile Object56_Profile = { Object56::create, 56, 70, NULL /* TODO: 0x0213d768 */ };
