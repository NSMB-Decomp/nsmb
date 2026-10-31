#include "Object160.hpp"

void *Object160::create()
{
	return new Object160();
}

s32 Object160::onCreate() {}
s32 Object160::onDestroy() {}
s32 Object160::onUpdate() {}
s32 Object160::onRender() {}

Object160_Unknown::Object160_Unknown() {}

Object160::Object160() {

}

void (Object160::*data_ov054_021718b8[10])() = {
    &Object160::func_ov054_0215f9dc,
    &Object160::func_ov054_0215f974,
    &Object160::func_ov054_0215f964,
    &Object160::func_ov054_0215f92c,
    NULL,
    &Object160::func_ov054_0215f7e4,
    NULL,
    &Object160::func_ov054_0215f794,
    &Object160::func_ov054_0215f748,
    &Object160::func_ov054_0215f710,
};
void (Object160::*data_ov054_021718a8[2])() = {
    &Object160::func_ov054_0215f6d8,
    &Object160::func_ov054_0215f400,
};

// 0x0216e2b0
ObjectProfile Object160_Profile = { Object160::create, 160, 6 };
