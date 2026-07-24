#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace Threads {

struct Context {
	u32 storage[0x30];
};

NITRO_SIZE_ASSERT(Context, 0xC0);

typedef void (*Entry)(void *);

extern "C" {

BOOL hasThreadTerminated(Context *context);
void createThread(
	Context *context,
	Entry entry,
	void *argument,
	void *stackTop,
	u32 stackSize,
	u32 priority
);
void setStackWarning(Context *context, u32 offset);
void wakeThread(Context *context);

}

}
}
