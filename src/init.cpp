#include "base_types.hpp"
void Nitro_Tick_Init();
void Nitro_Timer_Init();
void Nitro_MultiTHread_init();
void Nitro_Exception_SetHandler(u32, u32);
void Nitro_EnableDisplay();
void Nitro_Graphics_ResetOAM();
bool Nitro_Graphics_Step();
void ProcessManager_ExecuteTasks();

void SystemThreadsSleep();
void func_02005230();
void func_02021654();
void func_0200a594();
void func_020132a0();
void func_02014a44();
void func_01ff9010();

void func_0201031c();
void func_020058c0();
void func_02010094();
void func_02014a30();
void Graphics_2DStep();
void func_020123d8();

void InitGame() {

}

u32 FrameCounter;
u32 data_02085a78;
u32 data_02085a74;
void StartGameLoop() {
u32 *GFX_FIFO_SWAP_BUFFERS = (u32*)0x04000540;

    SystemThreadsSleep();
    Nitro_EnableDisplay();

    do {
        func_02005230();
        func_02021654();
        func_0200a594();
        Nitro_Graphics_ResetOAM();
        bool rendered_frame = Nitro_Graphics_Step();
        if (rendered_frame) {
            func_020132a0();
            ProcessManager_ExecuteTasks();
            func_02014a44();
        }
        FrameCounter +=1;
        func_01ff9010();
        *GFX_FIFO_SWAP_BUFFERS = (data_02085a78 << 1) | data_02085a74;
        func_0201031c();
        func_020058c0();
        func_02010094();
        func_02014a30();
        Graphics_2DStep();
        func_020123d8();
    } while (true);
}

void InitNitroMainGame() {
    // Temp values
    u32 a = 0x1234; // arm9_mainCODE
    u32 b = 0x4321; // autoload_3.bss 
    Nitro_Tick_Init();
    Nitro_Timer_Init();
    Nitro_MultiTHread_init();
    Nitro_Exception_SetHandler(a,b);

}

void InitMainGame() {
    InitNitroMainGame();
    InitGame();
    StartGameLoop();
}