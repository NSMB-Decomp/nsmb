#include "Object251.hpp"

void *Object251::create()
{
	return new Object251();
}

void *Object252::create()
{
	return new Object252();
}

void *Object253::create()
{
	return new Object253();
}

void (Object251::*data_ov054_021717a8)() = &Object251::func_ov054_02158d3c;
void (Object251::*data_ov054_021717a0)() = &Object251::func_ov054_02158be8;
void (Object251::*data_ov054_021717b0)() = &Object251::func_ov054_02158a94;

// 0x0216d9ac
ActorProfile Object251_Profile = { Object251::create, 251, 105, NULL };

// 0x0216d9b8
ActorProfile Object252_Profile = { Object252::create, 252, 107, NULL };

// 0x0216d9c4
ActorProfile Object253_Profile = { Object253::create, 253, 108, NULL };
