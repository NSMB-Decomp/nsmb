#include "MPLevelSelectScene.hpp"

extern u8 data_ov052_0215c88c;
extern u8 data_ov052_0215c890;
extern u8 data_ov052_0215c894;
extern u8 data_ov052_0215c898;
extern u8 data_ov052_0215c8a0[];
extern u8 data_ov052_0215aee4[];
extern u8 data_ov052_0215aee8[];
extern u8 data_ov052_0215aeec[];
extern u16 data_ov052_0215aef4[];
extern u16 data_ov052_0215af00[];
extern u8 data_0208ae54;

namespace Nitro {
	void func_02066f28(void *, void *, u32);
	u32 func_02062138();
}

extern "C" {

void func_02007bb4(Fader *);

void func_ov052_02153760()
{
	Nitro::func_02066f28((void *)0x05000460, (void *)0x05000440, 0x20);
}

void func_ov052_02153780()
{
	u8 topCount;
	u8 bottomCount;
	if (data_0208ae54 == 0) {
		topCount = data_ov052_0215c8a0[0];
		bottomCount = data_ov052_0215c8a0[1];
	} else {
		topCount = data_ov052_0215c8a0[1];
		bottomCount = data_ov052_0215c8a0[0];
	}

	u16 *tiles = (u16 *)(Nitro::func_02062138() + 0x840);
	for (s32 player = 0; player < topCount; player++, tiles += 3) {
		for (s32 row = 0; row < 3; row++) {
			for (s32 column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a6 + row * 0x20 + column;
		}
	}

	s32 selected = data_ov052_0215aee8[data_ov052_0215c894];
	tiles = (u16 *)(Nitro::func_02062138() + 0x840);
	tiles += selected * 3;
	for (; selected < 3; selected++, tiles += 3) {
		for (s32 row = 0; row < 3; row++) {
			for (s32 column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a0 + row * 0x20 + column;
		}
	}

	tiles = (u16 *)(Nitro::func_02062138() + 0x87a);
	for (s32 player = 0; player < bottomCount; player++, tiles -= 3) {
		for (s32 row = 0; row < 3; row++) {
			for (s32 column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a9 + row * 0x20 + column;
		}
	}

	selected = data_ov052_0215aee8[data_ov052_0215c894];
	tiles = (u16 *)(Nitro::func_02062138() + 0x87a);
	tiles -= selected * 3;
	for (; selected < 3; selected++, tiles -= 3) {
		for (s32 row = 0; row < 3; row++) {
			for (s32 column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a0 + row * 0x20 + column;
		}
	}
}

void func_ov052_021539c8(MPLevelSelectScene *scene)
{
	u8 *indexPtr = &data_ov052_0215c890;
	u16 *xTable = data_ov052_0215aef4;
	u8 index = *indexPtr;
	s32 originX = scene->_12c.x;
	u16 *yTable = data_ov052_0215af00;
	s32 xOffset = (u32)xTable[index] << 12;
	xOffset = -xOffset;
	scene->_138.x = originX + xOffset;
	s32 yOffset = (u32)yTable[index] << 12;
	yOffset = -yOffset;
	scene->_138.y = scene->_12c.y + yOffset;
}

void func_ov052_02153a1c(MPLevelSelectScene *scene)
{
	data_ov052_0215c898 |= 1 << data_ov052_0215c890;
	scene->_64 = 8;
	func_02007bb4(&GlobalFader);
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
