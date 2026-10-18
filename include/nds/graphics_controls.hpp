#pragma once

#include "../../lib/Nitro/Nitro.hpp"

#define NDS_VISIBLE_PLANE_BACKGROUND0 (1 << 0)
#define NDS_VISIBLE_PLANE_BACKGROUND1 (1 << 1)
#define NDS_VISIBLE_PLANE_BACKGROUND2 (1 << 2)
#define NDS_VISIBLE_PLANE_BACKGROUND3 (1 << 3)
#define NDS_VISIBLE_PLANE_OBJECTS     (1 << 4)

namespace NDS {
namespace Graphics {

inline void setMainObjectTileMapping1D128K()
{
	vu32 &displayControl = REG_DISPCNT;
	displayControl =
		(displayControl & ~((3 << 20) | (1 << 4))) | (2 << 20) | (1 << 4);
}

inline void setMainObjectCharacterBase(u32 base)
{
	vu32 &displayControl = REG_DISPCNT;
	displayControl = (displayControl & ~(7 << 24)) | (base << 24);
}

inline void setMainObjectScreenBase(u32 base)
{
	vu32 &displayControl = REG_DISPCNT;
	displayControl = (displayControl & ~(7 << 27)) | (base << 27);
}

inline void setMainVisiblePlanes(u32 planes)
{
	vu32 &displayControl = REG_DISPCNT;
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
	vu16 &backgroundControl = *(vu16 *)((u32)&REG_BG0CNT + background * 2);
	backgroundControl = (backgroundControl & 0x43) |
		(screenSize << 14) | (colorMode << 7) | (screenBase << 8) |
		(characterBase << 2) | (extendedPaletteSlot << 13);
}

inline void setMainBackgroundPriority(u32 background, u32 priority)
{
	vu16 &backgroundControl = *(vu16 *)((u32)&REG_BG0CNT + background * 2);
	backgroundControl = (backgroundControl & ~3) | priority;
}

inline void setMainBackgroundMosaicEnabled(u32 background, BOOL enabled)
{
	vu16 &backgroundControl = *(vu16 *)((u32)&REG_BG0CNT + background * 2);
	backgroundControl =
		(backgroundControl & ~(1 << 6)) | (enabled << 6);
}

// Writes BGnHOFS and BGnVOFS together: offsets = x | (y << 16).
inline void setMainBackgroundOffsets(u32 background, u32 offsets)
{
	*(vu32 *)((u32)&REG_BG0OFS + background * 4) = offsets;
}

inline u32 getSubVisiblePlanes()
{
	return (REG_DISPCNT_SUB & 0x1f00) >> 8;
}

inline void setSubVisiblePlanes(u32 planes)
{
	vu32 &displayControl = REG_DISPCNT_SUB;
	displayControl = (displayControl & ~0x1f00) | (planes << 8);
}

inline void setSubBackgroundPriority(u32 background, u32 priority)
{
	vu16 &backgroundControl = *(vu16 *)((u32)&REG_BG0CNT_SUB + background * 2);
	backgroundControl = (backgroundControl & ~3) | priority;
}

inline void setSubBackgroundMosaicEnabled(u32 background, BOOL enabled)
{
	vu16 &backgroundControl = *(vu16 *)((u32)&REG_BG0CNT_SUB + background * 2);
	backgroundControl =
		(backgroundControl & ~(1 << 6)) | (enabled << 6);
}

// Writes BGnHOFS and BGnVOFS together: offsets = x | (y << 16).
inline void setSubBackgroundOffsets(u32 background, u32 offsets)
{
	*(vu32 *)((u32)&REG_BG0OFS_SUB + background * 4) = offsets;
}

inline void setSubObjectTileMapping1D32K()
{
	vu32 &displayControl = REG_DISPCNT_SUB;
	displayControl =
		(displayControl & ~((3 << 20) | (1 << 4))) | (1 << 4);
}

inline void setSubObjectTileMapping2D()
{
	vu32 &displayControl = REG_DISPCNT_SUB;
	displayControl &= ~((3 << 20) | (1 << 4));
}

inline void configureSubTextBackground1(u32 screenSize, u32 colorMode,
	u32 screenBase, u32 characterBase, u32 extendedPaletteSlot)
{
	vu16 &backgroundControl = REG_BG1CNT_SUB;
	backgroundControl = (backgroundControl & 0x43) |
		(screenSize << 14) | (colorMode << 7) | (screenBase << 8) |
		(characterBase << 2) | (extendedPaletteSlot << 13);
}

inline void configureSubTextBackground(
	u32 background,
	u32 screenSize,
	u32 colorMode,
	u32 screenBase,
	u32 characterBase,
	u32 extendedPaletteSlot
)
{
	vu16 &backgroundControl = *(vu16 *)((u32)&REG_BG0CNT_SUB + background * 2);
	backgroundControl = (backgroundControl & 0x43) |
		(screenSize << 14) | (colorMode << 7) | (screenBase << 8) |
		(characterBase << 2) | (extendedPaletteSlot << 13);
}

}
}
