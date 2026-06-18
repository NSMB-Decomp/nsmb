// This file is used solely as a placeholder for functions with a currently unknown location.
// We should avoid using this file.
#pragma once
#include "Heap.hpp"
#include "ProcessManager.hpp"
#include "Vec.hpp"
#include "base_types.hpp"

inline i32 _FixedMul(i32 x, i32 y) {
	return (((i64)x * y) + 0x800LL) >> 12;
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

namespace FS
{
namespace Cache
{
void clear();
}
} // namespace FS

namespace Nitro_
{
void func_02063af0(u16[1], u32, u32);
}

namespace WiFi
{
u32 random();
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
extern i32 cameraY[2];
extern i32 cameraZoomY[2];
u32 getBootScene();
void drawBNCLSpriteSub(u32 id, void *data, u32 flags, u8 palette, u8 affineSet, Vec2_32 *scale, i16 rotation, i16 *rotation_center, u8 procSettings, u32 x, u32 y);
void* getPlayer(u32);
} // namespace Game


namespace Math {
	i32 expLerp(i32*, i32, i32, i32, i32);
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
extern Heap *data_0208b720;
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
bool func_020109c8();
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

void func_0200b87c();
extern u32 data_02087700;
void func_0200b83c(u32);
void func_02009a30(u32, u32, u32);
void func_02017190(u32);
SceneNode* func_020087f0();
void func_020087c0(SceneNode*);
extern u8 data_02088f30;
void func_020051ec();
void func_020045cc();
extern u32 data_02085a84;
extern u32 DAT_02039200;
void func_02008784(u32, void*);
u32 func_02009c64(u32, u32);
void func_02004564(u32, u32, u32);
void func_02021808();
void func_020180a4(void*);
void func_02005700();