#include "Object258.hpp"

void *Object258::create()
{
	return new Object258();
}

void (Object258::*data_ov098_021899c8)() = &Object258::func_ov098_021871f4;
void (Object258::*data_ov098_021899b8)() = &Object258::func_ov098_02187144;
void (Object258::*data_ov098_021899c0)() = &Object258::func_ov098_02187120;

// 0x021895d4
ActorProfile Object258_Profile = { Object258::create, 258, 171, NULL /* TODO: 0x0218778c */ };
