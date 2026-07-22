#pragma once

#include "../../src/base_types.hpp"

union Mat2x2;

namespace NDS {
namespace Graphics {

void setMainDisplayMode(u32 displayMode, u32 backgroundMode, u32 backgroundZeroMode);
u32 setSubDisplayMode(u32 backgroundMode);
void setMasterBrightness(void *registerAddress, s32 brightness);
void signalVerticalBlank(BOOL enabled);
void signalHorizontalBlank(BOOL enabled);

void disableMainBackgroundBank();
void disableMainObjectBank();
void disableMainBackgroundPaletteBank();
void disableMainObjectPaletteBank();
void disableTextureBank();
void disableTexturePaletteBank();
void disableClearImageBank();
void disableArm7Bank();
void disableLcdcBank();
void disableSubBackgroundBank();
void disableSubObjectBank();
void disableSubBackgroundPaletteBank();
void disableSubObjectPaletteBank();

void resetMainBackgroundBank();
void resetMainObjectBank();
void resetMainBackgroundPaletteBank();
void resetMainObjectPaletteBank();
void resetTextureBank();
void resetTexturePaletteBank();
void resetClearImageBank();
void resetSubBackgroundBank();
void resetSubObjectBank();
void resetSubBackgroundPaletteBank();
void resetSubObjectPaletteBank();

void assignMainBackgroundBank(u32 banks);
void assignMainObjectBank(u32 banks);
void assignMainBackgroundPaletteBank(u32 banks);
void assignMainObjectPaletteBank(u32 banks);
void assignTextureBank(u32 banks);
void assignTexturePaletteBank(u32 banks);
void assignLcdcBank(u32 banks);
void assignSubBackgroundBank(u32 banks);
void assignSubObjectBank(u32 banks);

u32 mainBackground0Map();
void *subBackground0Map();
u32 mainBackground1Map();
u32 mainBackground2Map();
u32 mainBackground3Map();
u32 subBackground1Map();
u32 subBackground2Map();
u32 subBackground3Map();
u32 mainBackground0Tiles();
u32 mainBackground1Tiles();
void *mainBackground2Tiles();
u32 mainBackground3Tiles();
void *subBackground1Tiles();
u32 subBackground2Tiles();
u32 subBackground3Tiles();

void applyAffine2D(void *registers, const Mat2x2 *matrix,
	s32 centerX, s32 centerY, s32 offsetX, s32 offsetY);
u32 uploadSubBackgroundPalette(u32 source, u32 offset, u32 size);
u32 uploadMainBackgroundPalette(u16 *source, u32 offset, u32 size);

void flushGeometry();
void initializeInterruptTable();
void enableDisplays();

inline void swapBuffers(u32 sortMode, u32 bufferMode)
{
	*reinterpret_cast<volatile u32 *>(0x04000540) = (sortMode << 1) | bufferMode;
}

}
}
