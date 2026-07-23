#pragma once

#include "../../src/base_types.hpp"

#define NDS_VISIBLE_PLANE_BACKGROUND0 (1 << 0)
#define NDS_VISIBLE_PLANE_BACKGROUND1 (1 << 1)
#define NDS_VISIBLE_PLANE_BACKGROUND2 (1 << 2)
#define NDS_VISIBLE_PLANE_BACKGROUND3 (1 << 3)
#define NDS_VISIBLE_PLANE_OBJECTS     (1 << 4)

namespace NDS {
namespace Graphics {

inline u32 getSubVisiblePlanes()
{
	return (*reinterpret_cast<volatile u32 *>(0x04001000) & 0x1f00) >> 8;
}

inline void setSubVisiblePlanes(u32 planes)
{
	volatile u32 &displayControl = *reinterpret_cast<volatile u32 *>(0x04001000);
	displayControl = (displayControl & ~0x1f00) | (planes << 8);
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
