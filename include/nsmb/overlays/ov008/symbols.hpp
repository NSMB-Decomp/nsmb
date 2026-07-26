#pragma once

#include "../../../../src/nsmb_nitro.hpp"
#include "../../../../src/Vec.hpp"

class WorldmapScene;
class TextBox;
struct TextBoxMessagePrefix;

namespace WM {
struct Node;
struct NodeLink;
struct Path;
extern int dialogMsgID;
}

struct Unk020d1478Config {
	s32 value00;
	s32 value04;
	s32 value08;
	s32 value0C;
	s32 padding10;
	u32 mode;
};
NTR_SIZE_GUARD(Unk020d1478Config, 0x18);
NTR_OFFSET_GUARD(Unk020d1478Config, value00, 0x0);
NTR_OFFSET_GUARD(Unk020d1478Config, value04, 0x4);
NTR_OFFSET_GUARD(Unk020d1478Config, value08, 0x8);
NTR_OFFSET_GUARD(Unk020d1478Config, value0C, 0xc);
NTR_OFFSET_GUARD(Unk020d1478Config, mode, 0x14);

struct WmInputSequenceEntry {
	u32 (*check)();
	u32 value04;
};
NTR_SIZE_GUARD(WmInputSequenceEntry, 0x8);
NTR_OFFSET_GUARD(WmInputSequenceEntry, check, 0x0);

struct WmWorldUnlockRule {
	u32 firstWorld;
	u32 secondWorld;
	u32 completionFlag;
};
NTR_SIZE_GUARD(WmWorldUnlockRule, 0xc);
NTR_OFFSET_GUARD(WmWorldUnlockRule, firstWorld, 0x0);
NTR_OFFSET_GUARD(WmWorldUnlockRule, secondWorld, 0x4);
NTR_OFFSET_GUARD(WmWorldUnlockRule, completionFlag, 0x8);

typedef void (WorldmapScene::*WorldmapSceneTask)();

extern "C" {
extern u32 data_ov008_020e2d3c[];
extern const u32 data_ov008_020e2d34[2];
extern const u32 data_ov008_020e2d44[];
extern fx32 data_ov008_020e2d58[][3];
extern fx32 data_ov008_020e2d5c[][3];
extern fx32 data_ov008_020e2d60[][3];
extern const s32 data_ov008_020e2d70[7];
extern const u32 data_ov008_020e2d8c[];
extern const u32 data_ov008_020e2dac[9];
extern const s16 data_ov008_020e2dd0[22];
extern WmInputSequenceEntry data_ov008_020e2dfc[];
extern const u32 data_ov008_020e5ec0[3];
extern const void* data_ov008_020e64d4[];
extern u32 data_ov008_020e650c[];
extern const void* data_ov008_020e6d70[];
extern const void* data_ov008_020e6d74[];
extern int data_ov008_020e64ec[][2];
extern u32 data_ov008_020e6714[][2];
extern u32 data_ov008_020e6718[][2];
extern u32 data_ov008_020e6bf0[][3];
extern u32 data_ov008_020e6bf4[][3];
extern u32 data_ov008_020e6bf8[][3];
extern const WmWorldUnlockRule data_ov008_020e6e38[9];
extern u32 data_ov008_020e77a4[][2][4];
extern u32 data_ov008_020e77a8[][2][4];
extern u32 data_ov008_020e77ac[][2][4];
extern u32 data_ov008_020e77b0[][2][4];
extern u32 data_ov008_020e8794[][16];
extern s8 data_ov008_020e5a2c;
extern const u8 data_ov008_020e5a30[2];
extern u8 data_ov008_020e5cc8[];
extern u8 data_ov008_020ee374;
extern u8 data_ov008_020ee378;
extern u8 data_ov008_020ee37c;
extern u8 data_ov008_020ee380;
extern u8 data_ov008_020ee384;
extern u8 data_ov008_020ee388;
extern u8 data_ov008_020ee38c;
extern u8 data_ov008_020ee390;
extern u8 data_ov008_020ee394;
extern u8 data_ov008_020ee398;
extern u8 data_ov008_020ee39c;
extern u8 data_ov008_020ee3a0;
extern u8 data_ov008_020ee3a4;
extern fx32 data_ov008_020ee3c4;
extern u32 data_ov008_020ee3d0;
extern u32 data_ov008_020ee3d4;
extern fx32 data_ov008_020ee3dc;
extern s32 data_ov008_020ee3e0;
extern fx32 data_ov008_020ee3ec;
extern u32 data_ov008_020ee3f0;
extern u32 data_ov008_020ee3f4;
extern fx32 data_ov008_020ee410;
extern u32 data_ov008_020ee414;
extern Unk020d1478Config data_ov008_020ee49c;
extern WorldmapSceneTask data_ov008_020ee4b4[];
extern TextBox data_ov008_020ee58c;
extern s32 data_ov008_020e8bfc[][2];
extern s32 data_ov008_020e8c00[][2];
extern fx32 data_ov008_020e8c8c[];
extern u32 data_ov008_020e93ec[];
extern u32 data_ov008_020e943c[];
extern const u32 data_ov008_020e955c[4];
extern const u32 data_ov008_020e9508[3];
extern const u32 data_ov008_020e954c[4];
extern const char* const data_ov008_020e953c[2][2];
extern const u32 data_ov008_020e95a8[8];
extern const u32 data_ov008_020e95c8[];
extern const u32 data_ov008_020e95e8[][3];
extern const s32 data_ov008_020e960c[];
extern const s32 data_ov008_020e9638[8][2];
extern const s32 data_ov008_020e9588[8];
extern const Mat3x3 data_ov008_020e96d0[];
extern const s32 data_ov008_020e9760[];
extern const s32 data_ov008_020e97f0[];
extern const char data_ov008_020e9880[];
extern Vec3_32 data_ov008_020ee63c[];
extern const u32 data_ov008_020e61ac[];

enum {
	WM_SAVE_COMPLETION_BIT_0 = 1 << 0,
	WM_SAVE_COMPLETION_BIT_1 = 1 << 1,
	WM_SAVE_COMPLETION_BIT_2 = 1 << 2,
	WM_SAVE_COMPLETION_BIT_3 = 1 << 3,
	WM_SAVE_COMPLETION_BIT_4 = 1 << 4,
	WM_SAVE_COMPLETION_BIT_5 = 1 << 5,
	WM_SAVE_COMPLETION_BIT_7 = 1 << 7,
	WM_SAVE_COMPLETION_BIT_8 = 1 << 8,
	WM_SAVE_COMPLETION_BIT_19 = 1 << 19,
	WM_SAVE_COMPLETION_BIT_20 = 1 << 20,
	WM_SAVE_COMPLETION_BIT_21 = 1 << 21,
	WM_SAVE_COMPLETION_BIT_22 = 1 << 22,
};

u32 func_ov008_020cdcf8();
u32 func_ov008_020cddd8();
u32 func_ov008_020cdec0();
u32 func_ov008_020cdf9c();
void func_ov008_020cdb70(int mode, int arrowValue);
void func_ov008_020cdbd0();
void func_ov008_020cdccc(u32 lastWorld);
u8 func_ov008_020cda24(u32 world, u32 path, u8 mask);
u16 func_ov008_020cda4c(u32 world, u32 node, u16 mask);
u16 func_ov008_020cda7c(u32 world);
WM::NodeLink* func_ov008_020cda94(u32 world, u32 node);
bool func_ov008_020cdab8(u32 world);
void func_ov008_020cdb44(u32 sceneID, u32 settings);
u8 func_ov008_020cdcac(u32 index);
void func_ov008_020ce0a0();
u32 func_ov008_020ce0d4(u32 index);
Vec3_32 func_ov008_020ce0e4(u32 index);
u32 func_ov008_020ce12c(u32 index);
u32 func_ov008_020ce13c(u32 index);
u32 func_ov008_020ce154(u32 index);
u32 func_ov008_020ce16c(u32 index);
fx32 func_ov008_020ce184(u32 index);
fx32 func_ov008_020ce1b4(u32 index);
u32 func_ov008_020ce1c4(u32 row, u32 column);
u32 func_ov008_020ce1d8(u32 row, u32 column);
u32 func_ov008_020ce1ec(u32 row, u32 column);
u32 func_ov008_020ce200(u32 row, u32 column);
u32 func_ov008_020ce214(u32 row, u32 column);
void func_ov008_020ce228();
void func_ov008_020ce22c();
u32 func_ov008_020ce298(u32 nodeType);
void func_ov008_020ce330(WorldmapScene* scene);
void func_ov008_020ce5ec();
void func_ov008_020ce674(WorldmapScene* scene);
void func_ov008_020ced20();
void func_ov008_020ced90(WorldmapScene* scene);
u32 func_ov008_020cf034(WorldmapScene* scene);
u32 func_ov008_020cf15c(WorldmapScene* scene);
u32 func_ov008_020cf7c8(WorldmapScene* scene);
void func_ov008_020cf790();
void func_ov008_020cf12c(WorldmapScene* scene, u32 state);
bool func_ov008_020cf794();
u32 func_ov008_020d04fc(WorldmapScene* scene);
void func_ov008_020d0534();
u32 func_ov008_020d0548(u32* value);
u32 func_ov008_020d0620();
u32 func_ov008_020d0644();
u32 func_ov008_020d0668();
u32 func_ov008_020d068c();
void func_ov008_020d12ac(Unk020d1478Config* config);
void func_ov008_020d1478(Unk020d1478Config* config, u32 mode);
void func_ov008_020d0614(u32* value);
void func_ov008_020d153c();
void func_ov008_020d1540();
TextBoxMessagePrefix* func_ov008_020cdc30(
	int boxID, int dialogBox, int textID);
}
