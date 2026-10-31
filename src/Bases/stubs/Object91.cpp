#include "Object91.hpp"

void *Object91::create()
{
	return new Object91();
}

void (Object91::*data_ov036_021438a0)() = &Object91::func_ov036_02142e9c;
void (Object91::*data_ov036_021438a8)() = &Object91::func_ov036_02142c74;
void (Object91::*data_ov036_021438e8)() = &Object91::func_ov036_02142bd8;
void (Object91::*data_ov036_021438e0)() = &Object91::func_ov036_02142ae4;
void (Object91::*data_ov036_021438d8)() = &Object91::func_ov036_021428fc;
void (Object91::*data_ov036_021438d0)() = &Object91::func_ov036_02142724;
void (Object91::*data_ov036_021438c8)() = &Object91::func_ov036_021425bc;
void (Object91::*data_ov036_021438c0)() = &Object91::func_ov036_02142420;
void (Object91::*data_ov036_021438b8)() = &Object91::func_ov036_021422c0;
void (Object91::*data_ov036_021438b0)() = &Object91::func_ov036_02142204;

// 0x02143770
ActorProfile Object91_Profile = { Object91::create, 91, 127, NULL /* TODO: 0x02143500 */ };
