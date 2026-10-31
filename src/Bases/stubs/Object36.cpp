#include "Object36.hpp"

void *Object36::create()
{
	return new Object36();
}

void (Object36::*data_ov012_02132508)() = &Object36::func_ov012_0213029c;
void (Object36::*data_ov012_02132510)() = &Object36::func_ov012_021301e0;
void (Object36::*data_ov012_02132500)() = &Object36::func_ov012_02130104;
void (Object36::*data_ov012_02132518)() = &Object36::func_ov012_021300bc;

// 0x021320a0
ActorProfile Object36_Profile = { Object36::create, 36, 49, NULL /* TODO: 0x02130864 */ };
