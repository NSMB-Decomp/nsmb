#include "Object242.hpp"

void *Object242::create()
{
	return new Object242();
}

void *Object243::create()
{
	return new Object243();
}

void *Object244::create()
{
	return new Object244();
}

void *Object245::create()
{
	return new Object245();
}

void *Object246::create()
{
	return new Object246();
}

void *Object247::create()
{
	return new Object247();
}

void (Object242::*data_ov054_0217266c)() = &Object242::func_ov054_0216b058;
void (Object242::*data_ov054_0217267c)() = &Object242::func_ov054_0216ad58;
void (Object242::*data_ov054_02172664)() = &Object242::func_ov054_0216ace0;
void (Object242::*data_ov054_02172684)() = &Object242::func_ov054_0216aad8;
void (Object242::*data_ov054_02172674)() = &Object242::func_ov054_0216a980;
void (Object242::*data_ov054_021726ac)() = &Object242::func_ov054_0216ac50;
void (Object242::*data_ov054_021726a4)() = &Object242::func_ov054_0216a944;
void (Object242::*data_ov054_0217269c)() = &Object242::func_ov054_0216a6c0;
void (Object242::*data_ov054_02172694)() = &Object242::func_ov054_0216a5d4;
void (Object242::*data_ov054_0217268c)() = &Object242::func_ov054_0216a510;

// 0x02171020
ActorProfile Object242_Profile = { Object242::create, 242, 96, NULL };

// 0x0217102c
ActorProfile Object243_Profile = { Object243::create, 243, 97, NULL };

// 0x02171038
ActorProfile Object244_Profile = { Object244::create, 244, 98, NULL };

// 0x02171044
ActorProfile Object245_Profile = { Object245::create, 245, 99, NULL };

// 0x02171050
ActorProfile Object246_Profile = { Object246::create, 246, 100, NULL };

// 0x0217105c
ActorProfile Object247_Profile = { Object247::create, 247, 101, NULL };
