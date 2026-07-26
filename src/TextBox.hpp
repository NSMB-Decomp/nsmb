#pragma once

#include "nsmb_nitro.hpp"

struct TextBoxMessagePrefix {
	u8 padding000[0x14e];
	u8 unk14E;
};
NTR_SIZE_GUARD(TextBoxMessagePrefix, 0x14f);
NTR_OFFSET_GUARD(TextBoxMessagePrefix, unk14E, 0x14e);

class TextBox {
public:
	void setDialogBox();
	void setStandardBox();
	void setDefaultBox();
	void loadSingleplayerDialogOptions();
	void renderArrows(int value, int unk1, int unk2);
	void renderText(int unk0, int unk1);
	TextBoxMessagePrefix* loadText_2(int textID, int* arguments);

	static void renderAButton(int unk0, int unk1);
};
