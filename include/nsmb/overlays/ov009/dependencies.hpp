#pragma once

#include "../../../../src/base_types.hpp"

class Vec3_32;
struct Save;

// Unresolved main-ARM9 dependencies used by overlay 009. Keep address names
// until binary evidence supports semantic names.
extern "C" u32 func_02012398(i32 soundID, Vec3_32 *position);
extern "C" void func_020180a4(void *textLabel);
extern "C" void func_02017bc4(void *textLabel, u32 *value, u32, s32 offset);
extern "C" s32 func_02012e08(u32 fileID, u32, Save *saveData);
extern "C" u32 func_02012934();
