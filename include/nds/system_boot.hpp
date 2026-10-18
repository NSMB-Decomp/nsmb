#pragma once

#include "../../lib/Nitro/Nitro.hpp"

namespace NDS {
namespace System {

inline u32 readBootSource()
{
	return (SYS_BOOT_PARAMS & 0xf0000) >> 16;
}

inline BOOL isBootStatus2()
{
	return SYS_BOOT_TYPE == 2;
}

}
}
