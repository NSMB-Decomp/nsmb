#pragma once

#include "../../../src/base_types.hpp"

class Vec3_32;

extern "C" u32 func_02022890(
	u32 emitter,
	u32 effectID,
	const Vec3_32* position,
	void* rotation,
	void* value,
	void* axis,
	u32 setting);
