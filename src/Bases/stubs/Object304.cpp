#include "Object304.hpp"

void *Object304::create()
{
	return new Object304();
}

// 0x0215c67c
ActorProfile Object304_Profile = { Object304::create, 304, 5, NULL /* TODO: 0x02159d9c */ };
