#include "../../src/base_types.hpp"

#define REG_DISPCNT     *((u32*)0x04000000)
#define REG_BG1CNT      *((u16*)0x0400000a)
#define REG_BLDCNT      *((u16*)0x04000050)
#define REG_KEYINPUT    *((u16*)0x04000130)
#define REG_IME         *((u16*)0x04000208)
#define REG_POWER_CNT   *((u16*)0x04000304)
#define REG_DISPCNT_SUB *((u32*)0x04001000)
#define REG_BG1CNT_SUB  *((u16*)0x0400100a)
#define REG_BLDCNT_SUB  *((u16*)0x04001050)

#define KEY_A        0 << 1
#define KEY_B        1 << 1
#define KEY_SELECT   2 << 1
#define KEY_START    3 << 1
#define KEY_RIGHT    4 << 1
#define KEY_LEFT     5 << 1
#define KEY_UP       6 << 1
#define KEY_DOWN     7 << 1
#define KEY_R        8 << 1
#define KEY_L        9 << 1
#define KEY_X       10 << 1
#define KEY_Y       11 << 1
#define KEY_DEBUG   12 << 1
#define KEY_FOLD    13 << 1

// All inputs other than FOLD
#define KEYS_ALL (KEY_A|KEY_B|KEY_SELECT|KEY_START|KEY_RIGHT|KEY_LEFT|KEY_UP|KEY_DOWN|KEY_R|KEY_L|KEY_X|KEY_Y|KEY_DEBUG)

class Vec3_32s {
public:
    i32 x;
    i32 y;
    i32 z;
};

// TODO: Seperate out files.
namespace Nitro {
    // FS - FileSystem
    void FS_Init();
    void FS_InitFile();
    void FS_OpenFile();
    void FS_SeekFile();
    void FS_ReadFile();
    void FS_IsFile();
    void FS_CloseFile();
    void FS_SeekFileToBegin();
    // OS - Operating System
    void OS_Init();
    void OS_InitTick();
    void OS_InitAlarm();
    void OS_SetIrqFunction();
    void OS_SetIrqCheckFlag();
    void OS_EnableIrqMask();
    void OS_EnableIrq();
    void OS_WaitVBlankIntr();
    void OS_Panic();
    void OS_LockMutex();
    void OS_UnlockMutex();
    void OS_InitMutex();
    void OS_TPrintf();
    void OS_ResetSystem();
    void OS_InitAlloc();
    void OS_Free();
    void OS_CreateThread();
    void OS_WakeupThreadDirect();
    void OS_ReceiveMessage();
    void OS_ReceiveMessage();
    void OS_SendMessage();
    void OS_SetPeriodicAlarm();
    void OS_CreateAlarm();
    void OS_GetConsoleType();
    void OS_CheckStack();
    void OS_Sleep();
    void OS_KillThread();
    void OS_IsThreadTerminated();
    void OS_CancelAlarm();
    void OS_GetResetParameter();
    void OS_KillThread();
    void OS_IsThreadTerminated();
    // FX
    void FX_Init();
    // GX - Graphics
    void GX_SetPower();
    void GX_DispOff();
    void GX_VBlankIntr();
    void GX_HBlankIntr();
    void GX_SetVisiblePlane();
    void GX_SetDispSelect();
    void GX_SetBankForLCDC();
    void GX_SetOBJVRamModeChar();
    void GX_SetBGCharOffset();
    void GX_SetBankForBG();
    void GX_SetBankForOBJ();
    void GX_SetBankForSubBG();
    void GX_SetBankForSubOBJ();
    void GX_SetGraphicsMode();
    // G2
    void G2_SetBG0Priority();
    void G2_SetBG1Priority();
    void G2_SetBG2Priority();
    void G2_SetBG3Priority();
    // G2S
    void G2S_SetBG0Priority();
    void G2S_SetBG1Priority();
    void G2S_SetBG2Priority();
    void G2S_SetBG3Priority();
    void MI_DmaFill32();
    // GXS
    void GXS_DispOff();
    void GXS_SetVisiblePlane();
    void GXS_SetGraphicsMode();
    void GXS_SetOBJVRamModeChar();
    // SND - Sound
    void SND_Init();
    // TP
    void TP_Init();
    // RTC - Real Time Clock
    void RTC_Init();
    // SND - Sound
    void SND_LockChannel();
    void SND_SetupChannelPcm();
    void SND_SetupAlarm();
    void SND_StartTimer();
    void SND_StopTimer();
    void SND_UnlockChannel();
    void SND_FlushCommand();
    // DC
    void DC_StoreRange();
    // G2
    void G2_GetBG3ScrPtr();
    // MO
    void MO_BlitFrameImage();
    void MO_GetNbFrame();
    void MO_GetAudioFrequency();
    // MI
    void MI_CpuFillFast();
    void MI_CpuClearFast();
    void MI_CpuCopy8(void*, void*, u32); // std::copy
    void MI_CpuCopy16(void*, void*, u32);
    void MI_CpuCopy32(void*, void*, u32);

    //
    void Math_AddVec3_32s(Vec3_32s*, Vec3_32s*, Vec3_32s*);
    void MultiThread_Init();
    void Exception_SetHandler(void*, void*);
    void Graphics_ResetOAM();
    bool Graphics_Step();
    inline void Graphics_SwapBuffer(u32 a, u32 b) {
        u32 *GFX_FIFO_SWAP_BUFFERS = (u32 *)0x04000540;
        *GFX_FIFO_SWAP_BUFFERS = (a << 1) | b;
    }
    void Math__stub();
    void func_02061588(u32);
    void EnableDisplay();
    void func_01ff8128(u32);
    void func_01ffa5ec(u32, u16);
    void func_02060e38(u32);
    void func_0206d554();
    void MainInit();
    void func_0206f3cc(void(*)());
    void func_02063fd4();
    void func_02066fe8(void *, u32, u32);
    void func_01ff9010();
    void func_01ff80e0(u32);
    void func_01ff9010();
    void FS_init();
    bool Wifi_isMultiBootCart();
    void FS_Overlays_loadOverlay(u32);
    void FS_Overlays_unload(u32);
    void FS_Archive_loadMainGameArchives();
    void func_02061ac4(u32);
    void func_020613c8(u32);
}