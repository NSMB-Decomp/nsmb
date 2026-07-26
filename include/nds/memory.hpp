#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace Memory {

struct LzStreamContext {
	void *destination;
	s32 remainingSize;
	u16 state08;
	u8 state0A;
	u8 flags;
	u8 flagsRemaining;
	u8 pendingReferenceByte;
	u8 hasPendingReferenceByte;
	u8 reserved0F;
};

NITRO_SIZE_ASSERT(LzStreamContext, 0x10);
NITRO_OFFSET_ASSERT(LzStreamContext, destination, 0x0);
NITRO_OFFSET_ASSERT(LzStreamContext, remainingSize, 0x4);
NITRO_OFFSET_ASSERT(LzStreamContext, state08, 0x8);
NITRO_OFFSET_ASSERT(LzStreamContext, flags, 0xb);
NITRO_OFFSET_ASSERT(LzStreamContext, flagsRemaining, 0xc);

void clearFast(u32 value, u32 destination, u32 size);
void clear16(u16 value, void *destination, u32 size);
void copyFast(void *source, void *destination, u32 size);
void copy8(void *source, void *destination, u32 size);
void fill8(void *destination, u32 value, u32 size);
void decompressLz16(u32 source, u32 destination);
void flushDataCache(void *address, u32 size);
void invalidateDataCache(void *address, u32 size);
void invalidateInstructionCache(void *address, u32 size);
void storeEntireDataCache();
void flushEntireDataCache();
void decompressLz8(const void *source, void *destination);
s32 consumeLzStream(
	LzStreamContext *context, const void *source, u32 sourceSize);
void initializeLzStream(
	LzStreamContext *context, void *destination, const u32 *header);

}
}
