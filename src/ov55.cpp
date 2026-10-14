#include "nsmb_nitro.hpp"
#include <nsmb/core/filesystem.hpp>

u8 ov55_heap[0x19000];
void initOv55Heap() {
  FS::Cache::overlayFileDestination = &ov55_heap;
  FS::Cache::overlayFileRemaining = 0x19000;
}
