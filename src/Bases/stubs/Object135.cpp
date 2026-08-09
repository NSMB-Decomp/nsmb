#include "Object135.hpp"

void *Object135::create()
{
	return new Object135();
}

// 0x021324f8
ActorProfile Object135_Profile = { Object135::create, 135, 153, NULL /* TODO: 0x021322fc */ };
