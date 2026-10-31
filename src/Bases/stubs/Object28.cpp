#include "Object28.hpp"

void *Object28::create()
{
	return new Object28();
}

void *Object30::create()
{
	return new Object30();
}

void (Object28::*data_ov025_02141e54)() = &Object28::func_ov025_0213e398;
void (Object28::*data_ov025_02141e44)() = &Object28::func_ov025_0213df5c;
void (Object28::*data_ov025_02141e4c)() = &Object28::func_ov025_0213ddf0;
void (Object28::*data_ov025_02141e34)() = &Object28::func_ov025_0213dc38;
void (Object28::*data_ov025_02141e3c)() = &Object28::func_ov025_0213db80;
void (Object28::*data_ov025_02141e5c)() = &Object28::func_ov025_0213d98c;

// 0x02141800
ActorProfile Object28_Profile = { Object28::create, 28, 40, NULL /* TODO: 0x0213ed3c */ };

// 0x0214180c
ActorProfile Object30_Profile = { Object30::create, 30, 42, NULL /* TODO: 0x0213ed3c */ };
