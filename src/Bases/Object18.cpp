#include "Object18.hpp"

extern u32 data_02085a84;
extern "C" void func_ov052_021594c4();

void *Object18::create()
{
	return new Object18();
}

s32 Object18::onRender() {

}

s32 Object18::onDestroy()
{
	if (BOOL(data_02085a84 != 0) != FALSE)
		func_ov052_021594c4();
	return true;
}

Object18::~Object18() {

}
