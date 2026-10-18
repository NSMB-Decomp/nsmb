#pragma once

#include "../../../../src/nsmb_nitro.hpp"

class TextLabel
{
public:
	TextLabel();
	~TextLabel();

	void func_02017b94();
	void func_02017bc4(u32 *value, u32, s32 offset);
	void func_02017e14(const u32 *value);
	void func_02017e2c(u32, u32);
	void func_02017ff8(u32 *textID);
	void func_02018060();
	void func_020180a4(); // unloadScript
	void func_020180c0(u32);

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
