// This file is used solely as a placeholder for functions with a currently unknown location.
// We should avoid using this file.

#include "base_types.hpp"
#include "ProcessManager.hpp"

struct ObjectProfile {
    Base* (*constructor)() ;
    u16 updatePriority;
    u16 renderPriority;
};

extern ObjectProfile** CurrentProfileTable;
extern ObjectProfile* MainProfileTable;
extern u8 Stage_actorFreezeFlag;

//
extern u8 data_0v000_020ca84c;

//
void Heap_deallocate(void*, void *);
void* Heap_allocate(void*, u32, i32);
extern void* data_0208b720;

//
bool func_0204d82c();

//
void SceneGraph_removeChild(ProcessList*, ProcessLink*);
void SceneGraph_addChild(ProcessList*, ProcessLink*, ProcessLink*);
void LinkedList_append(ProcessList*, PriorityNode*);
void LinkedList_Remove(ProcessList*, void*); // TODO: Confirm these paramaters, is it ProcessList or PTMF, and what is void*?
void LinkedList_Prepend(ProcessList*, ProcessNode*);
void ProcessSet_add(ProcessList*, PriorityNode*);

void Save_setupBackup(u32, void *);
void CardPulledOutCallback();
void SystemThreadsSleep();
void doFadingTransition();
void TouchPad_update();
void Input_update();
void Scene_tryChangeScene();
void Font_updateFont();
void Wifi_updatePackets();
void System_waitForVBlank();
void Wifi_update();
void func_02014a30();
void Graphics_2DStep();
void ProcessManager_ExecuteTasks();
void func_020123d8();
void func_02005ab0();
bool Wifi_isMultiBootCart();
void setupGraphicsForDebugScreen();
void Save_clearLoadedSaves();
void FS_init();
void FS_Overlays_loadOverlay(u32);
void FS_Overlays_unload(u32);
void FS_Archive_loadMainGameArchives();
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