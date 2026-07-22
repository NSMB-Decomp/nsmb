#pragma once

#include "../../../src/base_types.hpp"

namespace FS {

void init();

namespace Overlay {

void load(u32 overlayID);
void untrack(u32 overlayID);

}

namespace Archive {

void loadMainGameArchives();

}
}
