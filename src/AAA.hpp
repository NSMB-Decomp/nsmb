// This file is used solely as a placeholder for functions with a currently unknown location.
// We should avoid using this file.
#pragma once
#include "Heap.hpp"
#include "ProcessManager.hpp"
#include "Vec.hpp"
#include "base_types.hpp"

#define POWERUP_SMALL 0
#define POWERUP_SUPER 1
#define POWERUP_FIRE  2
#define POWERUP_MEGA  3
#define POWERUP_MINI  4
#define POWERUP_SHELL 5
#define POWERUP_6 6
#define POWERUP_7 7

extern i16 _FixedSinCosTbl[];

#define _FixedFlt(flt) ((i32)(flt * 4096.0))

inline i32 _FixedMul(i32 x, i32 y) {
	i64 result = (i64)x * (i64)y;
	result += 0x800;
    return (i32)(result >> 12);
}

inline i16 _FixedSin(int a) {
	return _FixedSinCosTbl[(a >> 4) * 2];
}

inline i16 _FixedCos(int a) {
	return _FixedSinCosTbl[(a >> 4) * 2 + 1];
}

struct ObjectProfile {
	void *(*constructor)();
	u16 updatePriority;
	u16 renderPriority;
};

struct ActorProfile {
// TODO: Can we rever this back to ActorProfile : ObjectProfile? I was unable to compile without doing the below.
	void *(*constructor)();
	u16 updatePriority;
	u16 renderPriority;
	bool (*loadResources)();
};

namespace FS {
	namespace Cache {

		// 0x0200A0B4
		void setupCacheEntries();

		// 0x02009CB4
		void* getFile(u32 extFileID);

		// 0x02009C64
		void* loadFile(u32 extFileID, bool compressed);

		// 0x02009C14
		void* loadFileToOverlay(u32 extFileID, bool compressed);

		// 0x02009BC8
		void* loadData(u32 size);

		// 0x02009B94
		bool unloadFile(u32 extFileID);

		// 0x02009B64
		void clear();

	}

	u32 loadFileLZ77(u32 extFileID, void* dest);

	void unloadFile(void* file);

	void* loadExtFile(u32 extFileID);

}

namespace Nitro_
{
void func_02063af0(u16[1], u32, u32);
}

namespace WiFi
{
u32 random();
}

struct BNBL {

};

struct BNCL_Cell {
	s16 posX   : 12;
	s16 alignX : 4;
	s16 posY   : 12;
	s16 alignY : 4;
	u8 graphics;
	u8 rsv[3];
};
size_assert(BNCL_Cell, 0x8);

struct BNCL {
	u32 magic;
	u16 rsv;
	u16 cellCount;
	BNCL_Cell cells[0];
};

struct BNCD {

};

namespace Layout {

	void drawCellSub(u32 cellIdx, const void* oamAttrs, u32 oamFlags, u8 palette, u8 affineSet, const Vec2_32* scale, u16 rot, const s16* rotCenter, u32 oamSettings);

	void drawCellMain(u32 cellIdx, const void* oamAttrs, u32 oamFlags, u8 palette, u8 affineSet, const Vec2_32* scale, u16 rot, const s16* rotCenter, u32 oamSettings);

	void getCellPosMain(Vec2_32& pos, u32 cellIdx);

	void drawCellSubEx(const BNCL_Cell* cell, const BNCL_Cell* refCell, bool sub, const Vec2_32* scale, u16 rot, s32 x, s32 y, u8 palette, u32 oamFlags);

	void initSub(const void* bncd, const void* bncl, const void* bnbl);

	extern u16 subBgColor;
	extern const BNBL* bnbl[2];
	extern const BNCL* bncl[2];
	extern const BNCD* bncd[2];

};

// These are shared between TitleScreen, Stage and Worldmap
extern "C" {
	extern u8 optionsMenuState;
	extern u8 optionsMenuSlideTimer;
	extern s32 optionsMenuSlideOffset;
}

namespace Stage
{
extern u16 ObjectBankTable[2];
extern u8 actorFreezeFlag;
extern u8 stageGroup;
extern u8 stageID;
extern u8 stageAreaID;
} // namespace Stage

namespace Game
{
extern u8 character; // old luigiMode
extern i32 cameraY[2];
extern i32 cameraZoomY[2];
u32 getBootScene();
void drawBNCLSpriteSub(u32 id, void *data, u32 flags, u8 palette, u8 affineSet, Vec2_32 *scale, i16 rotation, i16 *rotation_center, u8 procSettings, u32 x, u32 y);
void* getPlayer(u32);
} // namespace Game

#define C_DEG(d) s32((d * 0x10000) / 360)
namespace Math {
	i32 expLerp(i32*, i32, i32, i32, i32);

	inline s32 max(s32 a, s32 b) {
		//return a >= b ? a : b;
		return a < b ? b : a;
	}

	inline s32 min(s32 a, s32 b) {
		return a > b ? b : a;
	}

}
namespace Input
{
extern u8 localConsoleID;
extern u32 consoleKeys[4][2];
extern u32 consoleKeysRepeated[4];
} // namespace Input

void func_ov001_020cceb4();
class Fader
{
      public:
	u8 _pad0[0x5a4];
	i32 targetBrightness;
	u32 fadingMode;
	i32 brightnessFactor[2];
	i32 brightnessIncrement[2];
	u8 fadingTarget[2];
	u8 fadingState[2];
	u8 fadeMaskShape[2];
	u8 fadingType; /* 5C2 */

	Fader();

	bool isComplete();
	void setupSceneFading(u32, bool, bool);
	void func_02007e34(u32, u32);
	void func_02007cf8(u32, u32);
	bool func_02007c68();
	void func_02007df0(u32);
	bool func_02007cb0();
	void func_02007bd8();
	void func_02007bfc();
};
extern Fader GlobalFader;

extern ObjectProfile **CurrentProfileTable;
extern ObjectProfile *MainProfileTable;
extern u8 data_02088f34;

//
extern u8 data_ov000_020ca84c;
extern u8 data_020887fc;
extern u32 data_02085ad4[2];
struct SaveMapEntity {
	u8 node;
	u8 type;
};
struct SaveHeader {
	u32 magic;
	u32 flags;
};
size_assert(SaveHeader, 0x8);
struct GameSave {
	SaveHeader header;
	u32 completion;
	u32 lives;
	u32 coins;
	u32 score;
	u32 starCoinsCollected;
	u32 starCoinsSpent;
	u32 currentWorld;
	u32 savedWorld;
	u32 currentWorldNode;
	u32 savedWorldNode;
	u32 powerup;
	u32 tempScore;
	u32 bottomScreenTheme;
	BOOL miniMushroomUnlocked;
	u32 actorRespawnWorld;
	u32 seenLevelImages[6];
	u8 inventoryPowerup;
	u8 reserved0[3];
	u16 worldStates[8];
	u8 nodeStates[8][25];
	u8 pathStates[8][30];
	SaveMapEntity mapEntities[8][2];
};
size_assert(GameSave, 0x248);
struct MinigamesSave {
	SaveHeader header;
	u8 scores[18][13];
};
size_assert(MinigamesSave, 0xF4);
struct OptionSave {
	SaveHeader header;
	u32 soundMode;
	u32 controlOptions;
	u32 currentSlot;
};
size_assert(OptionSave, 0x14);
struct Save {
	GameSave game;
	MinigamesSave minigames;
	OptionSave options;
};
size_assert(Save, 0x350);
extern Save save;

//
u32(func_ov000_02098798)(void *, u32);
void(func_0200d578)();
extern u8 data_ov010_02129438;
extern u32 data_ov011_0212f180[23];
extern u32 data_02085a98;
void drawSprite(u32, u32, u32, u32, u32, u32, Vec2_32 *, u32, u32, u32);
void Heap_deallocate(Heap *, void *);
extern Heap *Memory_gameHeap;
void func_02020354(i8);
void func_02012398(i32, Vec3_32 *);
u32 func_020202a0();
i32 func_0202040c(i32);
extern u16 data_0203bd30;

//
bool func_0204d82c();
void func_020067dc();
extern i32 data_02085aa4;

//
bool SceneGraph_removeChild(SceneGraph *, ProcessLink *);
bool SceneGraph_addChild(SceneGraph *, ProcessLink *, ProcessLink *);
bool LinkedList_append(LinkedList *, PriorityNode *);
bool LinkedList_Remove(LinkedList *, void *); // TODO: Confirm these paramaters?
bool LinkedList_Prepend(LinkedList *, ProcessNode *);
void ProcessSet_add(ProcessList *, PriorityNode *);

void Save_setupBackup(u32, void *);
void CardPulledOutCallback();
void SystemThreadsSleep();
void doFadingTransition();
void TouchPad_update();
void Input_update();
void Font_updateFont();
void Wifi_updatePackets();
void System_waitForVBlank();
void Wifi_update();
void func_02014a30();
void Graphics_2DStep();
void ProcessManager_ExecuteTasks();
void func_020123d8();
void func_02005ab0();
void setupGraphicsForDebugScreen();
void Save_clearLoadedSaves();
void loadBuildtimeFile();
void TouchPad_init();
void prepareWifiStuff(u32);
void func_0204c8fc();
void func_02044ad8(u32, u32);
void func_0200a9d0();
void func_02006cf4();
void func_0200e508();
void Graphics_Init();
void func_020125d4();
void func_020125e8();
void func_02043d10();
void func_0202187c();
void func_020133a4();
void func_0200e040();
void func_02014a58();
void __stub_1();
void __stub_2();
void __stub_3();
void func_020455d8();
void __stub_4();
void func_0200a0b4();
void func_020050ec();
void func_020050d8();
void func_020050c0();
void onRender_3();
bool(func_0200ae9c)(Vec3_32 *);
bool(func_0201f000)(Vec3_32 *);
bool isMultiBootCart();
bool Wifi_isMinigames();
void InitGame();
void SetMasterGameMode(u32);
void SetBootScene(u32);
void SetExtraBootParam(u32);
extern u16 data_020850e8;
extern void (*data_0203981c)();
extern void (*data_02039820)();
extern void (*data_02039824)();
extern char GAME_NAME[8]; // = "Mario2d";
extern u32 FrameCounter;
extern u32 data_02085a78;
extern u32 data_02085a74;
void func_02014824(u32, u32);
void func_0201486c(u32, u32, u32);

extern u32 data_ov000_020ca2b8;
extern void (*data_02039968)(i32, i32);
extern u32 data_02085a88;
extern u32 data_02085e0c;

void func_0200b87c(); // OAM::setFilesUnloaded
extern u32 data_02087700; // OAM::curTileOffset
void func_0200b83c(u32); // OAM::loadFilesToVRAM
void func_02009a30(u32, u32, u32); // FS::loadOBJPalette
u32 func_02017190(u32); // Font::getScriptFileID
extern u8 data_02088f30; // Scene::allowSoftReset
void func_020051ec(); // App::forceDisplayOn
void func_020045cc(); // Exception::terminateCaught
extern u32 data_02085a84; // Game::vsMode
extern u32 DAT_02039200; // vtable for Vec3
void func_02021808(); // TP::updatePlayer
void func_020180a4(void*); // TextLabel::unloadScript
void func_02005700(); // System::resetSubBGVBlank

extern class Heap* Memory_gameHeap;
extern Mat4x3 Game_modelMatrix;

#define FN_INIT 0
#define FN_STEP(n) (n+1)
#define FN_EXIT -1

namespace MTX {

	void initialize(); // Does nothing

	void setRotationZ(Mat4x3& mtx, s16 angle);
	void setRotationY(Mat4x3& mtx, s16 angle);
	void setRotationX(Mat4x3& mtx, s16 angle);
	void setRotation(Mat4x3& mtx, s16 angleX, s16 angleY, s16 angleZ);

	inline void setRotation(Mat4x3& mtx, const Vec3_16s& vec) {
		setRotation(mtx, vec.x, vec.y, vec.z);
	}

	inline void setScale(Mat4x3& mtx, fx32 x, fx32 y, fx32 z) {

		mtx.v[0][0] = x; mtx.v[0][1] = 0; mtx.v[0][2] = 0;
		mtx.v[1][0] = 0; mtx.v[1][1] = y; mtx.v[1][2] = 0;
		mtx.v[2][0] = 0; mtx.v[2][1] = 0; mtx.v[2][2] = z;
		mtx.v[3][0] = 0; mtx.v[3][1] = 0; mtx.v[3][2] = 0;

	}

	void setTranslation(Mat4x3& mtx, fx32 x, fx32 y, fx32 z);

	inline void setTranslation(Mat4x3& mtx, const Vec3_32s& vec) {
		setTranslation(mtx, vec.x, vec.y, vec.z);
	}

	void rotateZ(Mat4x3& mtx, s16 angle);
	void rotateY(Mat4x3& mtx, s16 angle);
	void rotateX(Mat4x3& mtx, s16 angle);
	void rotate(Mat4x3& mtx, s16 angleX, s16 angleY, s16 angleZ);

	inline void rotate(Mat4x3& mtx, const Vec3_16s& vec) {
		rotate(mtx, vec.x, vec.y, vec.z);
	}

	void rotateReversed(Mat4x3& mtx, s16 angleX, s16 angleY, s16 angleZ);

	inline void rotateReversed(Mat4x3& mtx, const Vec3_16s& vec) {
		rotateReversed(mtx, vec.x, vec.y, vec.z);
	}

	void scale(Mat4x3& mtx, fx32 scaleX, fx32 scaleY, fx32 scaleZ);

	inline void scale(Mat4x3& mtx, fx32 value) {
		scale(mtx, value, value, value);
	}

	inline void scale(Mat4x3& mtx, const Vec3_32s& vec) {
		scale(mtx, vec.x, vec.y, vec.z);
	}

	void translate(Mat4x3& mtx, fx32 transX, fx32 transY, fx32 transZ);

	inline void translate(Mat4x3& mtx, const Vec3_32s& vec) {
		translate(mtx, vec.x, vec.y, vec.z);
	}

	inline void identity(Mat4x3& mtx) {

		fx32 i = 4096;

		mtx.v[0][0] = i; mtx.v[0][1] = 0; mtx.v[0][2] = 0;
		mtx.v[1][0] = 0; mtx.v[1][1] = i; mtx.v[1][2] = 0;
		mtx.v[2][0] = 0; mtx.v[2][1] = 0; mtx.v[2][2] = i;
		mtx.v[3][0] = 0; mtx.v[3][1] = 0; mtx.v[3][2] = 0;

	}

	inline void multiply(const Mat4x3& a, const Mat4x3& b, Mat4x3& ab) {
		ConcatMat4x3(&a, &b, &ab);
	}

}
