#pragma once
#include "scene.hpp"
#include "../Bases/Actor.hpp"
#include "../graphics/3d/modelanm.hpp"

class WmCharacter : public Actor {
public:
	typedef void (WmCharacter::*TaskFunc)();

	enum StateFlag {
		SF_UnkBit0 = 1 << 0,
		SF_UnkBit2 = 1 << 2,
		SF_UnkBit3 = 1 << 3,
	};

	enum {
		DrawableFlagUnkBit2 = 1 << 2,
		AnimFlagUnkBit3 = 1 << 3,
	};

	inline WmCharacter()
	{
	}

	inline ~WmCharacter()
	{
	}

	ModelAnm model;
	ModelAnm cursorModel;
	WM::Anim* anim;
	Vec3_32 targetPosition;
	TaskFunc taskFunc;
	u32 taskID;
	u32 startTask;
	s32 timer;
	u32 unk298;
	u32 unk29C;
	u32 unk2A0;
	u32 unk2A4;
	u32 unk2A8;
	fx32 savedY;
	u8 unk2B0;
	u8 playerID;
	u8 padding2B2[2];
};
NTR_SIZE_GUARD(WmCharacter, 0x2B4);
NTR_OFFSET_GUARD(WmCharacter, model, 0x120);
NTR_OFFSET_GUARD(WmCharacter, cursorModel, 0x1C8);
NTR_OFFSET_GUARD(WmCharacter, anim, 0x270);
NTR_OFFSET_GUARD(WmCharacter, targetPosition, 0x274);
NTR_OFFSET_GUARD(WmCharacter, taskFunc, 0x284);
NTR_OFFSET_GUARD(WmCharacter, taskID, 0x28C);
NTR_OFFSET_GUARD(WmCharacter, startTask, 0x290);
NTR_OFFSET_GUARD(WmCharacter, timer, 0x294);
NTR_OFFSET_GUARD(WmCharacter, unk2A0, 0x2A0);
NTR_OFFSET_GUARD(WmCharacter, unk2A4, 0x2A4);
NTR_OFFSET_GUARD(WmCharacter, unk2A8, 0x2A8);
NTR_OFFSET_GUARD(WmCharacter, savedY, 0x2AC);
NTR_OFFSET_GUARD(WmCharacter, unk2B0, 0x2B0);
NTR_OFFSET_GUARD(WmCharacter, playerID, 0x2B1);

struct WmCharacterResource {
	u32 fileID;
	u32 unk4;
};
NTR_SIZE_GUARD(WmCharacterResource, 0x8);

extern WmCharacter::TaskFunc data_ov008_020ee79c[4];
extern WmCharacter::TaskFunc data_ov008_020ee7bc[4];

extern u8 data_ov008_020ee384;
extern u8 data_ov008_020ee388;
extern u8 data_ov008_020ee3ac;
extern u8 data_ov008_020ee3b0;
extern u32 data_ov008_020ee3e8;
extern WmCharacterResource data_ov008_020e98d8[];
extern WmCharacterResource data_ov008_020e98dc[];

extern "C" WmCharacter* func_ov008_020db204(WmCharacter* character);
extern "C" WmCharacter* func_ov008_020db244(WmCharacter* character);
extern "C" bool func_ov008_020db28c();
extern "C" void func_ov008_020db2e0(WmCharacter* character);
extern "C" void func_ov008_020db354(WmCharacter* character, u32 taskID);
extern "C" void func_ov008_020db380(WmCharacter* character);
extern "C" void func_ov008_020db3d8(WmCharacter* character);
extern "C" void func_ov008_020db404(WmCharacter* character);
extern "C" void func_ov008_020db48c(WmCharacter* character);
extern "C" void func_ov008_020db790(WmCharacter* character);
extern "C" void func_ov008_020db7c4(WmCharacter* character);
extern "C" void func_ov008_020db7f4();
extern "C" bool func_ov008_020db7f8(WmCharacter* character);
extern "C" bool func_ov008_020db840(WmCharacter* character);
extern "C" void func_ov008_020db9fc();
extern "C" bool func_ov008_020dba00();
extern "C" bool func_ov008_020dba1c(WmCharacter* character);
extern "C" s32 func_ov008_020dbaf0(WmCharacter* character);
extern "C" WmCharacter* func_ov008_020dbc40();
