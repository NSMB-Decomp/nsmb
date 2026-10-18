#pragma once

#include "../../Scenes/Scene.hpp"
#include "../../Vec.hpp"
#include <nsmb/core/ui/text_label.hpp>

class VSMenuScene : public Scene
{
      public:
	u8 state;
	u8 selection;
	s8 selectionTimer;
	u8 reserved_67;
	u8 confirmationVisible;
	u8 reserved_69_6b[3];
	u32 initializedState;
	u32 subCellData;
	TextLabel textLabel;
	void *tilesetData;
	u32 tilesetSize;
	Vec2_32 mainBackgroundPosition;
	Vec2_32 selectionBackgroundPosition;
	i16 transitionTimer;
	u8 reserved_146_147[2];

	VSMenuScene();
	VSMenuScene(u32);
	~VSMenuScene();
	void func_ov052_02155cf8();
	void func_ov052_02155c9c();
	void func_ov052_02155ba8();
	void func_ov052_02155b00();
	void func_ov052_02155210();
	void func_ov052_021551e4();
	void func_ov052_0215515c();
	void func_ov052_021554dc();
	void func_ov052_02154c9c();
	void func_ov052_02154bb4();
	void func_ov052_02154a60();
	void func_ov052_0215476c();
	void func_ov052_021546d0();
	void func_ov052_02154698();
	void func_ov052_0215459c();
	void func_ov052_02155178();
	void func_ov052_02154b64();
	void func_ov052_02154af4();
	void func_ov052_02154a24();
	void func_ov052_0215454c();
	void func_ov052_021544a0();
	void func_ov052_02154c68();
	void func_ov052_02154c34();
	void func_ov052_021549f8();

	void func_ov052_02154244();
	void func_ov052_02154238();
	void func_ov052_02154220();
	void func_ov052_02153d5c();
	void func_ov052_02153d14();
	void func_ov052_02153d08();
	void func_ov052_02153b44();
	void func_ov052_02153b38();
	void func_ov052_02153ad0();
	void func_ov052_02153b04();
	void func_ov052_0215422c();
	void func_ov052_02153d2c();
	void func_ov052_02153d20();
	void func_ov052_02153cfc();
	void func_ov052_02153ac4();
	void func_ov052_02153ab8();
	void func_ov052_02153d50();
	void func_ov052_02153d44();
	void func_ov052_02153d38();
	static void *create();

	// Match settings and progress. These persist while the players move
	// between the menu and the battles.
	static u8 battlesPlayed;
	static u8 chooseCourse; // 0: the next course is picked at random
	static u8 starsOption; // index into starsToWin
	static u8 course; // 0-4
	static u8 battlesOption; // index into battlesToWin
	static u8 playedCourses; // one bit per course
	static u8 livesOption; // index into lives
	static u8 battleWins[2];

	static const u8 starsToWin[]; // 3, 5, 10
	static const u8 battlesToWin[]; // 1, 2, 3
	static const u8 courseIDs[];
	static const u16 courseCursorX[];
	static const u16 courseCursorY[];
	static const u32 lives[]; // 3, 5, 99

	s32 onCreate();
	s32 onDestroy();
	s32 onUpdate();
	s32 onRender();
	void pendingDestroy();
};

NTR_SIZE_GUARD(VSMenuScene, 0x148);
NTR_OFFSET_GUARD(VSMenuScene, state, 0x64);
NTR_OFFSET_GUARD(VSMenuScene, initializedState, 0x6c);
NTR_OFFSET_GUARD(VSMenuScene, textLabel, 0x74);
NTR_OFFSET_GUARD(VSMenuScene, tilesetData, 0x124);
NTR_OFFSET_GUARD(VSMenuScene, tilesetSize, 0x128);
NTR_OFFSET_GUARD(VSMenuScene, mainBackgroundPosition, 0x12c);
NTR_OFFSET_GUARD(VSMenuScene, selectionBackgroundPosition, 0x138);
NTR_OFFSET_GUARD(VSMenuScene, transitionTimer, 0x144);

struct T__ {
	u32 a;
	u32 b;
};
struct TTTTTTTTT {
	T__ _[20];
};
