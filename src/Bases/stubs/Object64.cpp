#include "Object64.hpp"

void *Object64::create()
{
	return new Object64();
}

void (Object64::*data_ov022_0213c680)() = &Object64::func_ov022_0213c034;

// 0x0213c548
ActorProfile Object64_Profile = { Object64::create, 64, 78, NULL /* TODO: 0x0213c45c */ };
