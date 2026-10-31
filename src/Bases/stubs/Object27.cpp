#include "Object27.hpp"

void *Object27::create()
{
	return new Object27();
}

void *Object238::create()
{
	return new Object238();
}

void (Object27::*data_ov042_02152828)() = &Object27::func_ov042_02149af0;

// 0x02151fb0
ActorProfile Object27_Profile = { Object27::create, 27, 38, NULL /* TODO: 0x0214a8d4 */ };

// 0x02151fbc
ActorProfile Object238_Profile = { Object238::create, 238, 39, NULL /* TODO: 0x0214a8b0 */ };
