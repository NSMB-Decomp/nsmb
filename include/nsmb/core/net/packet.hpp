#pragma once

#include "../../../../src/nsmb_nitro.hpp"

extern "C" {
void func_02010cc8(void *packetBuffer);
void func_02010c74(void *packetBuffer);
}

namespace Net {

class PacketBuffer
{
public:
	inline PacketBuffer() { func_02010cc8(this); }
	inline ~PacketBuffer() { func_02010c74(this); }

	u32 vtable;
	u8 *buffers[4];
	u8 sequencerID;
	u8 bufferSize;
	bool configured;
	u8 reserved_17;
};

}

NTR_SIZE_GUARD(Net::PacketBuffer, 0x18);
NTR_OFFSET_GUARD(Net::PacketBuffer, buffers, 0x4);
