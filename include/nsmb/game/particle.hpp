#pragma once

#include "../../../src/base_types.hpp"

class Vec3_32;

namespace Particle {

class Handler {
private:
	u8 reserved_004_7f4[0x7F0];

public:
	Handler();
	virtual ~Handler();
	void init(u32 mode);
	void updateParticles();
	static void renderParticles();
};
NTR_SIZE_GUARD(Handler, 0x7F4);

}

extern "C" u32 func_02022890(
	u32 emitter,
	u32 effectID,
	const Vec3_32* position,
	void* rotation,
	void* value,
	void* axis,
	u32 setting);
