#include "Object318.hpp"

void *Object318::create()
{
	return new Object318();
}

void (Object318::*data_ov008_020ee34c)() = &Object318::func_ov008_020ccd78;
void (Object318::*data_ov008_020ee344)() = &Object318::func_ov008_020ccd74;

// 0x020e58d0
ObjectProfile Object318_Profile = { Object318::create, 318, 1 };
