#pragma once

#include "../../../../src/base_types.hpp"

struct Ov130U16Stride10
{
	u16 value;
	u8 reserved_02_09[8];
};
NTR_SIZE_GUARD(Ov130U16Stride10, 0xa);
NTR_OFFSET_GUARD(Ov130U16Stride10, value, 0x0);

struct Ov130S16Stride10
{
	s16 value;
	u8 reserved_02_09[8];
};
NTR_SIZE_GUARD(Ov130S16Stride10, 0xa);
NTR_OFFSET_GUARD(Ov130S16Stride10, value, 0x0);

struct Ov130U8Stride10
{
	u8 value;
	u8 reserved_01_09[9];
};
NTR_SIZE_GUARD(Ov130U8Stride10, 0xa);
NTR_OFFSET_GUARD(Ov130U8Stride10, value, 0x0);

extern "C" void func_ov130_02135230(void *, u32);
extern "C" void func_ov130_02137518(u32);
extern "C" void func_ov130_02122f60();

extern u32 data_ov130_02137bf0;
extern u16 data_ov130_02137de0;
extern u16 data_ov130_02137de8;
extern u16 data_ov130_02137dec;
extern u32 data_ov130_02137df0;
extern Ov130U16Stride10 data_ov130_02137df8[];
extern Ov130S16Stride10 data_ov130_02137dfa[];
extern Ov130S16Stride10 data_ov130_02137dfc[];
extern Ov130S16Stride10 data_ov130_02137dfe[];
extern Ov130U8Stride10 data_ov130_02137e00[];
extern u8 data_ov130_021395e4;
extern u8 data_ov130_0213ace0;
extern u8 data_ov130_0213ace4;
extern void *data_ov130_0213ad08;
