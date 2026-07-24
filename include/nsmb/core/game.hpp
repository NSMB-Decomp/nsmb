#pragma once

#include "../../../src/base_types.hpp"

namespace Game {

void storeDataCache(const void *address, u32 size);
void flushDataCache(const void *address, u32 size);

}
