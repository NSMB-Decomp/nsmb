#include "nsmb_nitro.hpp"

u8 ov55_heap[0x19000];
void initOv55Heap() {
  currentHeap = (u32)&ov55_heap;
  currentHeapLength = 0x19000;
}
