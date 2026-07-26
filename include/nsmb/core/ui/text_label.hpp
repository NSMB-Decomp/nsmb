#pragma once

#include "../../../../src/nsmb_nitro.hpp"

extern "C" {
void func_02018114(void *textLabel);
void func_02018104(void *textLabel);
void func_02017e2c(void *textLabel, u32, u32);
void func_02017ff8(void *textLabel, u32 *textID);
void func_02017b94(void *textLabel);
}

class TextLabel
{
public:
	inline TextLabel() { func_02018114(this); }
	inline ~TextLabel() { func_02018104(this); }
	void func_02018060();

	struct ButtonPosition
	{
		s32 x;
		s32 y;
	};

	u32 vtable;
	u8 reserved_004_097[0x94];
	ButtonPosition buttonPositions[2];
	u8 reserved_0a8_0af[8];
};

NTR_SIZE_GUARD(TextLabel, 0xb0);
NTR_OFFSET_GUARD(TextLabel, buttonPositions, 0x98);
