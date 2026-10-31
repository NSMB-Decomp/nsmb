#include "Object240.hpp"

void *Object240::create()
{
	return new Object240();
}

void (Object240::*data_ov010_02129350)() = &Object240::func_ov010_020cff44;
void (Object240::*data_ov010_02129348)() = &Object240::func_ov010_020cfe0c;
void (Object240::*data_ov010_02129358)() = &Object240::func_ov010_020cfdf0;
void (Object240::*data_ov010_02129360)() = &Object240::func_ov010_020cfb84;

// 0x02124014
ActorProfile Object240_Profile = { Object240::create, 240, 43, NULL };
