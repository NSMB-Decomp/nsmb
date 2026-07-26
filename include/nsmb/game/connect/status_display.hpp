#pragma once

#include "../../../../src/nsmb_nitro.hpp"

class ConnectionStatusDisplay
{
public:
	struct Position16
	{
		s16 x;
		s16 y;
	};

	struct Sprite
	{
		u8 reserved_00_2f[0x30];
	};

	u8 reserved_00_07[8];
	void (ConnectionStatusDisplay::*renderCallback)();
	Sprite sprite;
	Position16 spritePosition;
	u8 reserved_44_4f[0xc];
	Position16 mainIconPosition;
	Position16 subIconPosition;
	u8 reserved_58_63[0xc];
	u32 spriteResource;
	u8 reserved_68_77[0x10];
	u32 animationState;
	u8 spriteFlags;
	u8 reserved_7d_7f[3];
};

NTR_SIZE_GUARD(ConnectionStatusDisplay, 0x80);
NTR_OFFSET_GUARD(ConnectionStatusDisplay, renderCallback, 0x8);
NTR_OFFSET_GUARD(ConnectionStatusDisplay, sprite, 0x10);
NTR_OFFSET_GUARD(ConnectionStatusDisplay, spritePosition, 0x40);
NTR_OFFSET_GUARD(ConnectionStatusDisplay, mainIconPosition, 0x50);
NTR_OFFSET_GUARD(ConnectionStatusDisplay, subIconPosition, 0x54);
NTR_OFFSET_GUARD(ConnectionStatusDisplay, animationState, 0x78);
NTR_OFFSET_GUARD(ConnectionStatusDisplay, spriteFlags, 0x7c);
