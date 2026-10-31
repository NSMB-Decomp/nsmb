#include "Object58.hpp"

void *Object58::create()
{
	return new Object58();
}

void (Object58::*data_ov042_02152808)() = &Object58::func_ov042_021470b0;
void (Object58::*data_ov042_02152800)() = &Object58::func_ov042_02146f7c;
void (Object58::*data_ov042_02152810)() = &Object58::func_ov042_02146e48;

// 0x02151c38
ActorProfile Object58_Profile = { Object58::create, 58, 72, NULL /* TODO: 0x021474d0 */ };
