#pragma once

#include "../../../src/base_types.hpp"

class Heap;

namespace Memory {

extern Heap *currentHeapPtr;
extern Heap *rootHeapPtr;

void *allocate(u32 size);
void *allocate(u32 size, s32 alignment);
void *allocate(Heap *heap, u32 size, s32 alignment);
void *reallocate(Heap *heap, void *memory, u32 size);
void deallocate(Heap *heap, void *memory);
void deallocate(void *memory);

}
