#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace System {

inline u32 readBootSource()
{
	return (*reinterpret_cast<volatile u32 *>(0x027ffc20) & 0xf0000) >> 16;
}

inline BOOL isBootStatus2()
{
	return *reinterpret_cast<volatile u16 *>(0x027ffc40) == 2;
}

}
}
