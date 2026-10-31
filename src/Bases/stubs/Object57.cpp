#include "Object57.hpp"

void *Object57::create()
{
	return new Object57();
}

void (Object57::*data_ov048_02148b80)() = &Object57::func_ov048_02147fd0;

// 0x02148a48
ActorProfile Object57_Profile = { Object57::create, 57, 71, NULL /* TODO: 0x02148680 */ };
