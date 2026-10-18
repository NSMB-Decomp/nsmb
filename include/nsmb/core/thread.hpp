#pragma once

#include <nds/thread.hpp>

class Heap;

namespace Memory {

void associateThreadHeap(NDS::Threads::Context *context, Heap *heap);

}
