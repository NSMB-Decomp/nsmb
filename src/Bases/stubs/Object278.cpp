#include "Object278.hpp"

void *Object278::create()
{
	return new Object278();
}

void *Object279::create()
{
	return new Object279();
}

// 0x021702a8
ActorProfile Object278_Profile = { Object278::create, 278, 309, NULL /* TODO: 0x02165bbc */ };

// 0x021702b4
ActorProfile Object279_Profile = { Object279::create, 279, 310, NULL /* TODO: 0x02165b88 */ };
