#pragma once

#include "../../../../src/nsmb_nitro.hpp"
#include "../../../../src/Vec.hpp"

class WorldmapScene;

struct Unk020d1478Config {
	u32 value00;
	u32 value04;
	u32 value08;
	u32 value0C;
	u32 padding10;
	u32 mode;
};
NTR_SIZE_GUARD(Unk020d1478Config, 0x18);
NTR_OFFSET_GUARD(Unk020d1478Config, value00, 0x0);
NTR_OFFSET_GUARD(Unk020d1478Config, value04, 0x4);
NTR_OFFSET_GUARD(Unk020d1478Config, value08, 0x8);
NTR_OFFSET_GUARD(Unk020d1478Config, value0C, 0xc);
NTR_OFFSET_GUARD(Unk020d1478Config, mode, 0x14);

namespace Game {
u8 getPlayerPowerup(s32 playerID);
}

extern "C" {
extern u32 data_ov008_020e2d3c[];
extern fx32 data_ov008_020e2d58[][3];
extern fx32 data_ov008_020e2d5c[][3];
extern fx32 data_ov008_020e2d60[][3];
extern u32 data_ov008_020e650c[];
extern u32 data_ov008_020e6714[][2];
extern u32 data_ov008_020e6bf0[][3];
extern u32 data_ov008_020e6bf4[][3];
extern u32 data_ov008_020e6bf8[][3];
extern u32 data_ov008_020e77a4[][2][4];
extern u32 data_ov008_020e77a8[][2][4];
extern u32 data_ov008_020e77ac[][2][4];
extern u32 data_ov008_020e77b0[][2][4];
extern u32 data_ov008_020e8794[][16];
extern u8 data_ov008_020e5a2c;
extern u8 data_ov008_020ee378;
extern u8 data_ov008_020ee37c;
extern u8 data_ov008_020ee398;
extern u32 data_ov008_020ee3d0;
extern u32 data_ov008_020ee3d4;
extern u32 data_ov008_020ee3e0;
extern u32 data_ov008_020ee3f0;
extern u32 data_ov008_020ee3f4;
extern u32 data_ov008_020ee414;
extern u8 data_ov008_020ee49c[];

enum {
	WM_SAVE_COMPLETION_BIT_5 = 1 << 5,
};

void func_ov008_020cdcf8();
void func_ov008_020cddd8();
u32 func_ov008_020cdec0();
u32 func_ov008_020cdf9c();
void func_ov008_020ce0a0();
u32 func_ov008_020ce0d4(u32 index);
Vec3_32 func_ov008_020ce0e4(u32 index);
u32 func_ov008_020ce12c(u32 index);
u32 func_ov008_020ce13c(u32 index);
u32 func_ov008_020ce154(u32 index);
u32 func_ov008_020ce16c(u32 index);
u32 func_ov008_020ce1b4(u32 index);
u32 func_ov008_020ce1c4(u32 row, u32 column);
u32 func_ov008_020ce1d8(u32 row, u32 column);
u32 func_ov008_020ce1ec(u32 row, u32 column);
u32 func_ov008_020ce200(u32 row, u32 column);
u32 func_ov008_020ce214(u32 row, u32 column);
void func_ov008_020ce228();
u32 func_ov008_020ce298(u32 nodeType);
void func_ov008_020ce5ec();
void func_ov008_020cf790();
void func_ov008_020cf12c(WorldmapScene* scene, u32 state);
bool func_ov008_020cf794();
u32 func_ov008_020d04fc();
void func_ov008_020d0534();
u32 func_ov008_020d0548(u32* value);
u32 func_ov008_020d0620();
u32 func_ov008_020d0644();
u32 func_ov008_020d0668();
u32 func_ov008_020d068c();
void func_ov008_020d06b0();
void func_ov008_020d06bc();
void func_ov008_020d06c8();
void func_ov008_020d06fc();
void func_ov008_020d0a4c();
void func_ov008_020d12ac(void* data);
void func_ov008_020d1478(Unk020d1478Config* config, u32 mode);
void func_ov008_020d0614(u32* value);
void func_ov008_020d153c();
void func_ov008_020d1540();
void func_ov008_020cdc30(u32 value0, u32 value1, u32 value2);
}
