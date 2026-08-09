#pragma once
#include "../StageEntity.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../Collision/Collider.hpp"
#include "../../AAA.hpp"

class BlockBase : public StageEntity {
public:
	Model model;	 /* 0x3F4 */
	Vec2_32 _484;	 /* 0x484 */
	Vec2_32 _490;	 /* 0x490 */
	u8 _pad0[0x4];

	inline BlockBase() {};
	inline ~BlockBase() {};
};

// MainProfileTable slot 254  |  ov010  |  profile @ 0x02125348
// vtable @ 0x02125360 (SpinBlock::vtable, anchored +8 in symbols.txt)
class SpinBlock : public BlockBase {
public:
	Collider collider; /* 0x4A0 */
	u8 _pad1[0x2c];
	Vec3_32 _52c;	   /* 0x52C */
	u8 _pad2[0x20];

	static void *create();
	inline SpinBlock() {};
	inline ~SpinBlock() {};
};

extern ActorProfile Object254_Profile;

// MainProfileTable slot 255  |  ov010  |  profile @ 0x0212533c  vtable @ 0x02125598
class Object255 : public SpinBlock {
public:
	static void *create();
	inline Object255() {};
	inline ~Object255() {};
};

extern ActorProfile Object255_Profile;

// MainProfileTable slot 256  |  ov010  |  profile @ 0x02125354  vtable @ 0x0212547c
class Object256 : public SpinBlock {
public:
	static void *create();
	inline Object256() {};
	inline ~Object256() {};
};

extern ActorProfile Object256_Profile;
