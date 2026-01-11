// This file is used solely as a placeholder for functions with a currently unknown location.
// We should avoid using this file.

#include "base_types.hpp"
#include "ProcessManager.hpp"
#include "Heap.hpp"
#include "Vec.hpp"


struct ObjectProfile
{
    void* (*constructor)();
    u16 updatePriority;
    u16 renderPriority;
};

struct ActorProfile : ObjectProfile {
    void* (*loadResources)();
};

namespace FS {
    namespace Cache {
        void clear();
    }
}

namespace Nitro_ {
    void func_02063af0(u16[1], u32, u32);
}

namespace WiFi {
    u32 random();
}

namespace Stage {
    extern u16 ObjectBankTable[2];
    extern u8 actorFreezeFlag;
    extern u8 stageGroup;
    extern u8 stageID;
    extern u8 stageAreaID;
}

namespace Game {
    extern i32 cameraY[2];
    extern i32 cameraZoomY[2];
}

namespace Input {
    extern u8 localConsoleID;
    extern u32 consoleKeys[4][2];
    extern u32 consoleKeysRepeated[4];
}

class Fader {
public:
    u8 _pad0[0x5ac];
    i32 brightnessFactor[2];
    u8 _pad1[0x8];
    u8 fadingTarget[2];
    bool isComplete();
};
extern Fader GlobalFader; 

extern ObjectProfile** CurrentProfileTable;
extern ObjectProfile* MainProfileTable;
extern u8 data_02088f34;

//
extern u8 data_ov000_020ca84c;
extern u8 data_020887fc;
extern u32 data_02085ad4[2];
struct SaveOptions {
    u32 header;
    u32 flags;
    u32 soundMode;
    u32 controlOptions;
    u32 currentSlot;
};
extern SaveOptions data_02088bdc;

//
void Heap_deallocate(Heap*, void *);
extern Heap* data_0208b720;

//
bool func_0204d82c();
void func_020067dc();
extern i32 data_02085aa4;

//
bool SceneGraph_removeChild(SceneGraph*, ProcessLink*);
bool SceneGraph_addChild(SceneGraph*, ProcessLink*, ProcessLink*);
bool LinkedList_append(LinkedList*, PriorityNode*);
bool LinkedList_Remove(LinkedList*, void*); // TODO: Confirm these paramaters?
bool LinkedList_Prepend(LinkedList*, ProcessNode*);
void ProcessSet_add(ProcessList*, PriorityNode*);

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
void func_ov001_020cceb4();
bool (func_0200ae9c)(Vec3_32*);
bool (func_0201f000)(Vec3_32*);
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
extern char GAME_NAME[8];// = "Mario2d";
extern u32 FrameCounter;
extern u32 data_02085a78;
extern u32 data_02085a74;

extern u32 data_ov000_020ca2b8;
extern void (*data_02039968)(i32, i32);