#include "Object70.hpp"

void *Object70::create()
{
	return new Object70();
}

void (Object70::*data_ov056_0217595c)() = &Object70::func_ov056_02174804;
void (Object70::*data_ov056_02175964)() = &Object70::func_ov056_02174758;
void (Object70::*data_ov056_0217597c)() = &Object70::func_ov056_02174684;
void (Object70::*data_ov056_02175974)() = &Object70::func_ov056_021744ec;
void (Object70::*data_ov056_0217596c)() = &Object70::func_ov056_021743f4;

// 0x02175818
ActorProfile Object70_Profile = { Object70::create, 70, 82, NULL /* TODO: 0x021751d8 */ };
