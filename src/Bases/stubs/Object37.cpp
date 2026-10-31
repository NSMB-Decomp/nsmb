#include "Object37.hpp"

void *Object37::create()
{
	return new Object37();
}

void *Object38::create()
{
	return new Object38();
}

void (Object37::*data_ov024_0213faa0)() = &Object37::func_ov024_0213e0cc;
void (Object37::*data_ov024_0213faa8)() = &Object37::func_ov024_0213e04c;
void (Object37::*data_ov024_0213fa98)() = &Object37::func_ov024_0213dfa8;
void (Object37::*data_ov024_0213fa90)() = &Object37::func_ov024_0213de60;
void (Object37::*data_ov024_0213fab8)() = &Object37::func_ov024_0213ddec;
void (Object37::*data_ov024_0213fab0)() = &Object37::func_ov024_0213dd74;

// 0x0213f6d0
ActorProfile Object37_Profile = { Object37::create, 37, 51, NULL /* TODO: 0x0213e364 */ };

// 0x0213f6dc
ActorProfile Object38_Profile = { Object38::create, 38, 52, NULL /* TODO: 0x0213e364 */ };
