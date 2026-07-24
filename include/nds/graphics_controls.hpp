#pragma once

#include "../../src/base_types.hpp"

#define NDS_VISIBLE_PLANE_BACKGROUND0 (1 << 0)
#define NDS_VISIBLE_PLANE_BACKGROUND1 (1 << 1)
#define NDS_VISIBLE_PLANE_BACKGROUND2 (1 << 2)
#define NDS_VISIBLE_PLANE_BACKGROUND3 (1 << 3)
#define NDS_VISIBLE_PLANE_OBJECTS     (1 << 4)

namespace NDS {
namespace Graphics {

inline void setMainObjectTileMapping1D128K()
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04000000);
	displayControl =
		(displayControl & ~((3 << 20) | (1 << 4))) | (2 << 20) | (1 << 4);
}

inline void setMainObjectCharacterBase(u32 base)
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04000000);
	displayControl = (displayControl & ~(7 << 24)) | (base << 24);
}

inline void setMainObjectScreenBase(u32 base)
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04000000);
	displayControl = (displayControl & ~(7 << 27)) | (base << 27);
}

inline void setMainVisiblePlanes(u32 planes)
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04000000);
	displayControl = (displayControl & ~0x1f00) | (planes << 8);
}

inline void configureMainTextBackground(
	u32 background,
	u32 screenSize,
	u32 colorMode,
	u32 screenBase,
	u32 characterBase,
	u32 extendedPaletteSlot
)
{
	volatile u16 &backgroundControl =
		*reinterpret_cast<volatile u16 *>(0x04000008 + background * 2);
	backgroundControl = (backgroundControl & 0x43) |
		(screenSize << 14) | (colorMode << 7) | (screenBase << 8) |
		(characterBase << 2) | (extendedPaletteSlot << 13);
}

inline void setMainBackgroundPriority(u32 background, u32 priority)
{
	volatile u16 &backgroundControl =
		*reinterpret_cast<volatile u16 *>(0x04000008 + background * 2);
	backgroundControl = (backgroundControl & ~3) | priority;
}

inline void setMainBackgroundHorizontalOffset(u32 background, u32 offset)
{
	*reinterpret_cast<volatile u32 *>(0x04000010 + background * 4) = offset;
}

inline u32 getSubVisiblePlanes()
{
	return (*reinterpret_cast<volatile u32 *>(0x04001000) & 0x1f00) >> 8;
}

inline void setSubVisiblePlanes(u32 planes)
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04001000);
	displayControl = (displayControl & ~0x1f00) | (planes << 8);
}

inline void setSubBackgroundPriority(u32 background, u32 priority)
{
	volatile u16 &backgroundControl =
		*reinterpret_cast<volatile u16 *>(0x04001008 + background * 2);
	backgroundControl = (backgroundControl & ~3) | priority;
}

inline void setSubBackgroundMosaicEnabled(u32 background, BOOL enabled)
{
	volatile u16 &backgroundControl =
		*reinterpret_cast<volatile u16 *>(0x04001008 + background * 2);
	backgroundControl =
		(backgroundControl & ~(1 << 6)) | (enabled << 6);
}

inline void setSubBackgroundHorizontalOffset(u32 background, u32 offset)
{
	*reinterpret_cast<volatile u32 *>(0x04001010 + background * 4) = offset;
}

inline void setSubObjectTileMapping1D32K()
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04001000);
	displayControl =
		(displayControl & ~((3 << 20) | (1 << 4))) | (1 << 4);
}

inline void setSubObjectTileMapping2D()
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04001000);
	displayControl &= ~((3 << 20) | (1 << 4));
}

inline void configureSubTextBackground1(u32 screenSize, u32 colorMode,
	u32 screenBase, u32 characterBase, u32 extendedPaletteSlot)
{
	volatile u16 &backgroundControl = *reinterpret_cast<volatile u16 *>(0x0400100a);
	backgroundControl = (backgroundControl & 0x43) |
		(screenSize << 14) | (colorMode << 7) | (screenBase << 8) |
		(characterBase << 2) | (extendedPaletteSlot << 13);
}

}
}
