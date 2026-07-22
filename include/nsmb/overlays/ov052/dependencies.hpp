#pragma once

#include "../../../../src/base_types.hpp"

class MPLevelSelectScene;
class Fader;
struct NicknameInfo;

extern "C" {
void func_0200419c(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32, s32);
void func_02018060(void *);
void func_020180c0(void *, u32);
void func_02017e14(void *, const u32 *);
void func_02006ca4();
void func_0201df50();
void func_02020628();
void func_02011e3c(u32);
s32 func_02046c78();
s32 func_0200e7ac(u32);
void func_0200e7b8(u32);
void func_0200e7c4(u32);
u32 func_02009acc(u32);
void func_ov052_021535a0();
void func_ov052_02152bf0();
void func_ov000_020bd604();
void func_ov052_02153a1c(MPLevelSelectScene *);
u8 func_ov052_02153a80();
void func_ov052_02153760(MPLevelSelectScene *scene);
void func_ov052_02153780(MPLevelSelectScene *scene);
void func_ov052_021539c8(MPLevelSelectScene *);
void func_ov053_0215cc70();
}

namespace Wifi {
NicknameInfo *func_02001050(s32 aid);
u8 *func_0200102c(s32 aid);
void func_02001000();
void func_020010a8();
}

namespace Layout {
void initSub(void *, void *, void *);
}

namespace System {
void setupSubBGVBlank();
void resetSubBGVBlank();
void setSubBGPosition(u32, s32, s32);
}

namespace StageScene {
void func_ov000_020a2eec();
}
