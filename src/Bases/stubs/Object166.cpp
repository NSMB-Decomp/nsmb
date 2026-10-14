#include "Object166.hpp"

void *Object166::create()
{
	return new Object166();
}

void *Object166::create2()
{
	return new Object166();
}

// 0x02125f28
ActorProfile Object167_Profile = { Object166::create2, 167, 206, NULL /* TODO: 0x020dc7c4 */ };

// 0x02125f34
ActorProfile Object166_Profile = { Object166::create, 166, 205, NULL /* TODO: 0x020dc7c4 */ };
