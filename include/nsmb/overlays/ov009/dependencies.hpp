#pragma once

#include "../../../../src/base_types.hpp"

class Vec3_32;
class Fader;
struct Save;

// Unresolved main-ARM9 dependencies used by overlay 009. Keep address names
// until binary evidence supports semantic names.
u32 func_02012398(i32 soundID, Vec3_32 *position);
void func_020180a4(void *textLabel);
void func_02017bc4(void *textLabel, u32 *value, u32, s32 offset);
s32 func_02012e08(u32 fileID, u32, Save *saveData);
u32 func_02012934();
void func_0204dad8(u32 character);
void func_02011c84(const void *, const void *);
void func_02011ce4(u32, u32);
void func_ov000_020bd604();
void func_ov000_020bd63c();

namespace Layout {
void initSub(void *, void *, void *);
}
