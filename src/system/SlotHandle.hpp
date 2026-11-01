#pragma once
#include "../nsmb_nitro.hpp"

// Placeholder name: claims one of 32 slots (bitmask at 0x02088a60) on construction and frees it on destruction.
class SlotHandle
{
      public:
	s32 slot;

	SlotHandle();
	virtual ~SlotHandle();
};
