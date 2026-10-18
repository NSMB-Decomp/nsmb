#include "VSMenuScene.hpp"
#include <nsmb/arm9/symbols.hpp>
#include <nsmb/overlays/ov052/dependencies.hpp>
#include <nsmb/overlays/ov052/symbols.hpp>
#include <nds/graphics.hpp>
#include <nds/memory.hpp>

void func_ov052_02153760(VSMenuScene *)
{
	NDS::Memory::copyFast(BG_PALETTE_SUB + 0x30, BG_PALETTE_SUB + 0x20, 0x20);
}

// Win markers are drawn on sub BG2's second 32x32 screen block, row 1:
// the top player's from column 0 rightwards, the bottom player's from
// column 29 leftwards.
static inline u16 *winMarkerTiles(u32 column)
{
	return (u16 *)(NDS::Graphics::subBackground2Map() + (32 * 32 + 32 + column) * sizeof(u16));
}

void func_ov052_02153780(VSMenuScene *)
{
	u8 topWins;
	u8 bottomWins;
	if (data_0208ae54[0] == 0) {
		topWins = VSMenuScene::battleWins[0];
		bottomWins = VSMenuScene::battleWins[1];
	} else {
		topWins = VSMenuScene::battleWins[1];
		bottomWins = VSMenuScene::battleWins[0];
	}

	u16 *tiles = winMarkerTiles(0);
	s32 player;
	s32 row;
	s32 column;
	for (player = 0; player < topWins; player++, tiles += 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a6 + row * 0x20 + column;
		}
	}

	s32 selected = VSMenuScene::battlesToWin[VSMenuScene::battlesOption];
	tiles = winMarkerTiles(0);
	s32 tileOffset = selected * 3;
	tiles += tileOffset;
	for (; selected < 3; selected++, tiles += 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a0 + row * 0x20 + column;
		}
	}

	tiles = winMarkerTiles(29);
	for (player = 0; player < bottomWins; player++, tiles -= 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a9 + row * 0x20 + column;
		}
	}

	selected = VSMenuScene::battlesToWin[VSMenuScene::battlesOption];
	tiles = winMarkerTiles(29);
	tileOffset = selected * 3;
	tiles -= tileOffset;
	for (; selected < 3; selected++, tiles -= 3) {
		for (row = 0; row < 3; row++) {
			for (column = 0; column < 3; column++)
				tiles[row * 0x20 + column] = 0x60a0 + row * 0x20 + column;
		}
	}
}

// Matching workaround: the ROM negates the offset and then adds it. Writing
// `a - b` or `a + -b` directly folds into a single SUB.
// TODO: find the source form (probably a typed fixed-point offset) that
// produces RSB + ADD without this helper.
static inline s32 negateOffset(u32 offset)
{
	return -offset;
}

void func_ov052_021539c8(VSMenuScene *scene)
{
	u32 selection = VSMenuScene::course;
	scene->selectionBackgroundPosition.x = scene->mainBackgroundPosition.x +
		negateOffset((u32)VSMenuScene::courseCursorX[selection] << 12);
	scene->selectionBackgroundPosition.y = scene->mainBackgroundPosition.y +
		negateOffset((u32)VSMenuScene::courseCursorY[selection] << 12);
}

void func_ov052_02153a1c(VSMenuScene *scene)
{
	VSMenuScene::playedCourses |= 1 << VSMenuScene::course;
	scene->state = 8;
	GlobalFader.prepareFadeIn();
}

u8 func_ov052_02153a64()
{
	return VSMenuScene::battlesToWin[VSMenuScene::battlesOption];
}

u8 func_ov052_02153a80()
{
	return VSMenuScene::courseIDs[VSMenuScene::course];
}

u8 func_ov052_02153a9c()
{
	return VSMenuScene::starsToWin[VSMenuScene::starsOption];
}
