#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace Interrupts {

void disableMask(u32 mask);
void enableMask(u32 mask);
void enableCpuInterrupts();

}

namespace Cpu {

u32 readMode();

}

namespace Power {

void initializeManagement();
u32 getDisplayPower();
u32 setDisplayPower(u32 power);
void getBacklights(u32 *top, u32 *bottom);
u32 setBacklight(u32 target, u32 level);
u32 sleep(u32 flags, u32 parameter2, u32 parameter3);

}

namespace Clock {

void initializeCounter();
void initializeAlarms();

}

namespace System {

void initialize();
void reset(u32 parameter);
void halt();

}

namespace Threads {

void initialize();

}

namespace Exceptions {

void installHandler(void *handler, void *argument);

}

namespace Card {

void setRemovalCallback(BOOL (*callback)());

}

namespace Graphics3D {

void initializeTextureArena(u32 slots, u32 mode);
void initializePaletteArena(u32 address, u32 mode);
void resetEngine();

}
}
