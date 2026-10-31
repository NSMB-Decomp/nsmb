#include "Object250.hpp"

void *Object250::create()
{
	return new Object250();
}

void (Object250::*data_ov098_021899a8)() = &Object250::func_ov098_02185f00;
void (Object250::*data_ov098_021899b0)() = &Object250::func_ov098_02185e80;
void (Object250::*data_ov098_021899a0)() = &Object250::func_ov098_02185e38;

// 0x02189478
ActorProfile Object250_Profile = { Object250::create, 250, 106, NULL /* TODO: 0x02186414 */ };
