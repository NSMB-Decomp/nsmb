#include "Object41.hpp"

void *Object41::create()
{
	return new Object41();
}

void *Object42::create()
{
	return new Object42();
}

void (Object41::*data_ov071_021799a8)() = &Object41::func_ov071_021763ac;
void (Object41::*data_ov071_021799b0)() = &Object41::func_ov071_02176298;
void (Object41::*data_ov071_021799a0)() = &Object41::func_ov071_02176184;

// 0x02179378
ActorProfile Object41_Profile = { Object41::create, 41, 55, NULL /* TODO: 0x02177468 */ };

// 0x02179384
ActorProfile Object42_Profile = { Object42::create, 42, 56, NULL /* TODO: 0x02177484 */ };
