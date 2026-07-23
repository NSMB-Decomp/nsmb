#pragma once

#include "../../../../src/base_types.hpp"

class Vec3_32;
class Fader;
struct Save;

// Unresolved main-ARM9 dependencies used by overlay 009. Keep address names
// until binary evidence supports semantic names.
extern "C" u32 func_02012398(i32 soundID, Vec3_32 *position);
extern "C" void func_020180a4(void *textLabel);
extern "C" void func_02017bc4(void *textLabel, u32 *value, u32, s32 offset);
extern "C" s32 func_02012e08(u32 fileID, u32, Save *saveData);
extern "C" s32 func_02012d98(u32 fileID, Save *saveData);
extern "C" u32 func_02012934();
extern "C" void func_0204dad8(u32 character);
extern "C" void func_02010a84();
extern "C" void func_02007bd8(Fader *fader);
extern "C" void func_02011c84(const void *, const void *);
extern "C" void func_02011ce4(u32, u32);
extern "C" void func_ov000_020bd604();
extern "C" void func_ov000_020bd63c();

namespace Layout {
void initSub(void *, void *, void *);
}
