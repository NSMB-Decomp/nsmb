#include "../base_types.hpp"

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
}