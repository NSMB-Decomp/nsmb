#pragma once

#include <nds/thread.hpp>

class Heap;

namespace Memory {

extern "C" void associateThreadHeap(NDS::Threads::Context *context, Heap *heap);

}
