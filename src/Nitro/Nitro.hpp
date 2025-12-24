#include "../base_types.hpp"

// TODO: Seperate out files.
namespace Nitro {
    void Tick_Init();
    void Timer_Init();
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
}