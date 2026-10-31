#include "Object60.hpp"

void *Object60::create()
{
	return new Object60();
}

void (Object60::*data_ov025_02141e20)() = &Object60::func_ov025_0213cb90;
void (Object60::*data_ov025_02141e28)() = &Object60::func_ov025_0213c13c;

// 0x021416b0
ActorProfile Object60_Profile = { Object60::create, 60, 74, NULL /* TODO: 0x0213cf30 */ };
