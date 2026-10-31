#include "Object68.hpp"

void *Object68::create()
{
	return new Object68();
}

void *Object88::create()
{
	return new Object88();
}

void *Object89::create()
{
	return new Object89();
}

void (Object68::*data_ov056_02175944)() = &Object68::func_ov056_0217336c;
void (Object68::*data_ov056_02175954)() = &Object68::func_ov056_021730c0;
void (Object68::*data_ov056_0217594c)() = &Object68::func_ov056_02172e18;

// 0x02175478
ActorProfile Object68_Profile = { Object68::create, 68, 80, NULL /* TODO: 0x02173ad8 */ };

// 0x02175484
ActorProfile Object88_Profile = { Object88::create, 88, 111, NULL /* TODO: 0x02173ad8 */ };

// 0x02175490
ActorProfile Object89_Profile = { Object89::create, 89, 112, NULL /* TODO: 0x02173ad8 */ };
