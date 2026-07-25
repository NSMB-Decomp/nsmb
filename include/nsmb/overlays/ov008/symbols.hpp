#pragma once

#include "../../../../src/nsmb_nitro.hpp"
#include "../../../../src/Vec.hpp"

class WorldmapScene;

namespace WM {
struct Node;
struct NodeLink;
struct Path;
}

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

struct WmWorldNodesSlot {
	WM::Node* nodes;
	u8 padding04[0x24];
};
NTR_SIZE_GUARD(WmWorldNodesSlot, 0x28);
NTR_OFFSET_GUARD(WmWorldNodesSlot, nodes, 0x0);

struct WmWorldPathsSlot {
	WM::Path* paths;
	u8 padding04[0x24];
};
NTR_SIZE_GUARD(WmWorldPathsSlot, 0x28);
NTR_OFFSET_GUARD(WmWorldPathsSlot, paths, 0x0);

struct WmWorldNodeCountSlot {
	u16 nodeCount;
	u8 padding02[0x26];
};
NTR_SIZE_GUARD(WmWorldNodeCountSlot, 0x28);
NTR_OFFSET_GUARD(WmWorldNodeCountSlot, nodeCount, 0x0);

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
extern u32 data_ov008_020e6718[][2];
extern u32 data_ov008_020e6bf0[][3];
extern u32 data_ov008_020e6bf4[][3];
extern u32 data_ov008_020e6bf8[][3];
extern u32 data_ov008_020e77a4[][2][4];
extern u32 data_ov008_020e77a8[][2][4];
extern u32 data_ov008_020e77ac[][2][4];
extern u32 data_ov008_020e77b0[][2][4];
extern u32 data_ov008_020e8794[][16];
extern WmWorldNodesSlot data_ov008_020e79c4[];
extern WmWorldPathsSlot data_ov008_020e79c8[];
extern WmWorldNodeCountSlot data_ov008_020e79e4[];
extern u8 data_ov008_020e5a2c;
extern u8 data_ov008_020e5cc8[];
extern u8 data_ov008_020ee378;
extern u8 data_ov008_020ee37c;
extern u8 data_ov008_020ee380;
extern u8 data_ov008_020ee388;
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
u8 func_ov008_020cda24(u32 world, u32 path, u8 mask);
u16 func_ov008_020cda4c(u32 world, u32 node, u16 mask);
u16 func_ov008_020cda7c(u32 world);
WM::NodeLink* func_ov008_020cda94(u32 world, u32 node);
void func_ov008_020cdb44(u32 sceneID, u32 settings);
u8 func_ov008_020cdcac(u32 index);
void func_ov008_020ce0a0();
u32 func_ov008_020ce0d4(u32 index);
Vec3_32 func_ov008_020ce0e4(u32 index);
u32 func_ov008_020ce12c(u32 index);
u32 func_ov008_020ce13c(u32 index);
u32 func_ov008_020ce154(u32 index);
u32 func_ov008_020ce16c(u32 index);
u32 func_ov008_020ce184(u32 index);
u32 func_ov008_020ce1b4(u32 index);
u32 func_ov008_020ce1c4(u32 row, u32 column);
u32 func_ov008_020ce1d8(u32 row, u32 column);
u32 func_ov008_020ce1ec(u32 row, u32 column);
u32 func_ov008_020ce200(u32 row, u32 column);
u32 func_ov008_020ce214(u32 row, u32 column);
void func_ov008_020ce228();
void func_ov008_020ce22c();
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
