#include "Object55.hpp"

void *Object55::create()
{
	return new Object55();
}

void *Object56::create()
{
	return new Object56();
}

void (Object55::*data_ov024_0213fa88)() = &Object55::func_ov024_0213d070;
void (Object55::*data_ov024_0213fa80)() = &Object55::func_ov024_0213cfbc;
void (Object55::*data_ov024_0213fa70)() = &Object55::func_ov024_0213cea4;
void (Object55::*data_ov024_0213fa78)() = &Object55::func_ov024_0213cb80;
void (Object55::*data_ov024_0213fa60)() = &Object55::func_ov024_0213cadc;
void (Object55::*data_ov024_0213fa68)() = &Object55::func_ov024_0213c710;

// 0x0213f450
ActorProfile Object55_Profile = { Object55::create, 55, 69, NULL /* TODO: 0x0213d768 */ };

// 0x0213f45c
ActorProfile Object56_Profile = { Object56::create, 56, 70, NULL /* TODO: 0x0213d768 */ };
