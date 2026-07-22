#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace Input {

inline BOOL isLidClosed()
{
	return (*reinterpret_cast<volatile u16 *>(0x027fffa8) & 0x8000) >> 15;
}

}
}
