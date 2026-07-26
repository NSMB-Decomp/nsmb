#pragma once

#include "../../src/nsmb_nitro.hpp"

namespace NDS {
namespace Graphics3D {

enum GeometryStateFlag {
	GeometryStateFlagBits4_6 = 0x50,
	GeometryStateFlagBits3_5_6_7 = 0xE8
};

struct RuntimeState {
	u8 _padding000[0x8];
	Mat4x4 projectionMatrix;
	u8 _padding048[0x4];
	Mat4x3 cameraMatrix;
	u8 _padding07C[0x80];
	u32 flags;
	u8 _padding100[0x140];
	Vec3_32s cameraPosition;
	Vec3_32s cameraUp;
	Vec3_32s cameraTarget;
};
NTR_SIZE_GUARD(RuntimeState, 0x264);
NTR_OFFSET_GUARD(RuntimeState, projectionMatrix, 0x8);
NTR_OFFSET_GUARD(RuntimeState, cameraMatrix, 0x4C);
NTR_OFFSET_GUARD(RuntimeState, flags, 0xFC);
NTR_OFFSET_GUARD(RuntimeState, cameraPosition, 0x240);
NTR_OFFSET_GUARD(RuntimeState, cameraUp, 0x24C);
NTR_OFFSET_GUARD(RuntimeState, cameraTarget, 0x258);

extern RuntimeState runtimeState;

}
}
