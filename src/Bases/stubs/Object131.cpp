#include "Object131.hpp"

void *Object131::create()
{
	return new Object131();
}

void *Object132::create()
{
	return new Object132();
}

void *Object133::create()
{
	return new Object133();
}

// 0x0213ba78
ActorProfile Object131_Profile = { Object131::create, 131, 149, NULL /* TODO: 0x021387f4 */ };

// 0x0213ba84
ActorProfile Object132_Profile = { Object132::create, 132, 150, NULL /* TODO: 0x0213875c */ };

// 0x0213ba90
ActorProfile Object133_Profile = { Object133::create, 133, 151, NULL /* TODO: 0x02138724 */ };
