#pragma once
#include "scene.hpp"
#include "../Bases/Actor.hpp"
#include "../graphics/3d/modelanm.hpp"

struct ActorProfile;

struct WmCharacterResource {
	u32 modelFileID;
	u32 animFileID;
};
NTR_SIZE_GUARD(WmCharacterResource, 0x8);

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

	virtual s32 onCreate() override;
	virtual s32 onDestroy() override;
	virtual s32 onUpdate() override;
	virtual s32 onRender() override;
	virtual void pendingDestroy() override;
	virtual bool onHeapCreated() override;

	static ActorProfile profile;
	static WmCharacterResource resources[2];

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

struct WmCharacterTaskRaw {
	void (*function)(WmCharacter*);
	s32 adjustment;
};
NTR_SIZE_GUARD(WmCharacterTaskRaw, 0x8);

union WmCharacterTaskEntry {
	WmCharacterTaskRaw raw;
	WmCharacter::TaskFunc member;
};
NTR_SIZE_GUARD(WmCharacterTaskEntry, 0x8);

extern WmCharacter::TaskFunc data_ov008_020ee79c[4];
extern WmCharacter::TaskFunc data_ov008_020ee7bc[4];
extern WmCharacterTaskEntry data_ov008_020e988c;
extern WmCharacterTaskEntry data_ov008_020e9894;
extern WmCharacterTaskEntry data_ov008_020e989c;
extern WmCharacterTaskEntry data_ov008_020e98a4;
extern WmCharacterTaskEntry data_ov008_020e98ac;
extern WmCharacterTaskEntry data_ov008_020e98b4;
extern WmCharacterTaskEntry data_ov008_020e98bc;
extern WmCharacterTaskEntry data_ov008_020e98c4;

extern u8 data_ov008_020ee3ac;
extern u8 data_ov008_020ee3b0;
extern fx32 data_ov008_020ee3e8;

extern "C" WmCharacter* func_ov008_020db204(WmCharacter* character);
extern "C" WmCharacter* func_ov008_020db244(WmCharacter* character);
extern "C" bool func_ov008_020db28c();
extern "C" void func_ov008_020db2e0(WmCharacter* character);
extern "C" void func_ov008_020db354(WmCharacter* character, u32 taskID);
extern "C" void WmCharacter_mainTask3(WmCharacter* character);
extern "C" void WmCharacter_setupTask3(WmCharacter* character);
extern "C" void WmCharacter_mainTask2(WmCharacter* character);
extern "C" void WmCharacter_setupTask2(WmCharacter* character);
extern "C" void WmCharacter_mainTask1(WmCharacter* character);
extern "C" void WmCharacter_setupTask1(WmCharacter* character);
extern "C" void WmCharacter_mainTask0(WmCharacter* character);
extern "C" void WmCharacter_setupTask0(WmCharacter* character);
extern "C" void* func_ov008_020dbc40();
