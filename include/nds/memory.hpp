#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace Memory {

void clearFast(u32 value, u32 destination, u32 size);
void clear16(u16 value, void *destination, u32 size);
void copyFast(void *source, void *destination, u32 size);
void copy8(void *source, void *destination, u32 size);
void fill8(void *destination, u32 value, u32 size);
void decompressLz16(u32 source, u32 destination);

}
}
