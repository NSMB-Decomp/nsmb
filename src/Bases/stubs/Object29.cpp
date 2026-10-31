#include "Object29.hpp"

void *Object29::create()
{
	return new Object29();
}

void (Object29::*data_ov067_021768a4)() = &Object29::func_ov067_02176150;
void (Object29::*data_ov067_021768ac)() = &Object29::func_ov067_02175cfc;

// 0x02176770
ActorProfile Object29_Profile = { Object29::create, 29, 41, NULL /* TODO: 0x021765f0 */ };
