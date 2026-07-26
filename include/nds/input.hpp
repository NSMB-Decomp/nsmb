#pragma once

#include "../../src/base_types.hpp"

namespace NDS {
namespace Input {

enum Button {
	ButtonA     = 1 << 0,
	ButtonB     = 1 << 1,
	ButtonSelect = 1 << 2,
	ButtonStart = 1 << 3,
	ButtonRight = 1 << 4,
	ButtonLeft  = 1 << 5,
	ButtonUp    = 1 << 6,
	ButtonDown  = 1 << 7,
	ButtonR     = 1 << 8,
	ButtonL     = 1 << 9,
	ButtonX     = 1 << 10,
	ButtonY     = 1 << 11,
};

inline BOOL isLidClosed()
{
	return (*reinterpret_cast<volatile u16 *>(0x027fffa8) & 0x8000) >> 15;
}

}
}
