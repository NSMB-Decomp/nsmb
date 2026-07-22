#include "MPLevelSelectScene.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov052/dependencies.hpp>
#include <nsmb/overlays/ov052/symbols.hpp>
#include <nds/graphics.hpp>
#include <nds/memory.hpp>

extern "C" {

void func_ov052_02153760(MPLevelSelectScene *)
{
	NDS::Memory::copyFast((void *)0x05000460, (void *)0x05000440, 0x20);
}

void func_ov052_02153780(MPLevelSelectScene *)
{
	u8 topCount;
	u8 bottomCount;
	if (data_0208ae54[0] == 0) {
		topCount = data_ov052_0215c8a0[0];
		bottomCount = data_ov052_0215c8a0[1];
	} else {
		topCount = data_ov052_0215c8a0[1];
		bottomCount = data_ov052_0215c8a0[0];
	}

	u16 *tiles = (u16 *)(NDS::Graphics::subBackground2Map() + 0x840);
	s32 player;
	s32 row;
	s32 column;
	for (player = 0; player < topCount; player++, tiles += 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a6 + row * 0x20 + column;
		}
	}

	s32 selected = data_ov052_0215aee8[data_ov052_0215c894];
	tiles = (u16 *)(NDS::Graphics::subBackground2Map() + 0x840);
	s32 tileOffset = selected * 3;
	tiles += tileOffset;
	for (; selected < 3; selected++, tiles += 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a0 + row * 0x20 + column;
		}
	}

	tiles = (u16 *)(NDS::Graphics::subBackground2Map() + 0x87a);
	for (player = 0; player < bottomCount; player++, tiles -= 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a9 + row * 0x20 + column;
		}
	}

	selected = data_ov052_0215aee8[data_ov052_0215c894];
	tiles = (u16 *)(NDS::Graphics::subBackground2Map() + 0x87a);
	tileOffset = selected * 3;
	tiles -= tileOffset;
	for (; selected < 3; selected++, tiles -= 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a0 + row * 0x20 + column;
		}
	}
}

static inline s32 negateOffset(u32 offset)
{
	return -offset;
}

void func_ov052_021539c8(MPLevelSelectScene *scene)
{
	u32 selection = data_ov052_0215c890;
	scene->selectionBackgroundPosition.x = scene->mainBackgroundPosition.x +
		negateOffset((u32)data_ov052_0215aef4[selection] << 12);
	scene->selectionBackgroundPosition.y = scene->mainBackgroundPosition.y +
		negateOffset((u32)data_ov052_0215af00[selection] << 12);
}

void func_ov052_02153a1c(MPLevelSelectScene *scene)
{
	data_ov052_0215c898 |= 1 << data_ov052_0215c890;
	scene->state = 8;
	GlobalFader.prepareFadeIn();
}

u8 func_ov052_02153a64()
{
	return data_ov052_0215aee8[data_ov052_0215c894];
}

u8 func_ov052_02153a80()
{
	return data_ov052_0215aeec[data_ov052_0215c890];
}

u8 func_ov052_02153a9c()
{
	return data_ov052_0215aee4[data_ov052_0215c88c];
}

}
