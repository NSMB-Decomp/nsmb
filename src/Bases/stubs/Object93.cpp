#include "Object93.hpp"

void *Object93::create()
{
	return new Object93();
}

void (Object93::*data_ov040_02146c40)() = &Object93::func_ov040_02145dec;
void (Object93::*data_ov040_02146c50)() = &Object93::func_ov040_021455f0;
void (Object93::*data_ov040_02146c48)() = &Object93::func_ov040_0214560c;

// 0x021469b0
ActorProfile Object93_Profile = { Object93::create, 93, 121, NULL /* TODO: 0x021462c8 */ };
