#include "Object230.hpp"

void *Object230::create()
{
	return new Object230();
}

void (Object230::*data_ov088_021826a0[6])() = {
    &Object230::func_ov088_0217e0e8,
    &Object230::func_ov088_0217e0bc,
    &Object230::func_ov088_0217e054,
    &Object230::func_ov088_0217dfac,
    &Object230::func_ov088_0217df78,
    &Object230::func_ov088_0217df14,
};
void (Object230::*data_ov088_021826d0[6])() = {
    &Object230::func_ov088_0217e0c0,
    &Object230::func_ov088_0217e07c,
    &Object230::func_ov088_0217dfd4,
    &Object230::func_ov088_0217df7c,
    &Object230::func_ov088_0217df3c,
    &Object230::func_ov088_0217de94,
};

// 0x02181f00
ActorProfile Object230_Profile = { Object230::create, 230, 193, NULL /* TODO: 0x0217dcb8 */ };
