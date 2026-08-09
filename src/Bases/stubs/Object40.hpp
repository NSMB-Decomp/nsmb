#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 40  |  ov042  |  profile @ 0x021526c0
class Object40 : public StageEntity {
public:
	ModelAnm _3f4;
	Model _49c;
	Model _52c;
	u8 _pad0[0x74];

	static void *create();
	inline Object40() {};
	inline ~Object40() {};
};

extern ActorProfile Object40_Profile;

// MainProfileTable slot 123  |  ov042  |  profile @ 0x021526cc
class Object123 : public StageEntity {
public:
	static void *create();
	inline Object123() {};
	inline ~Object123() {};
};

extern ActorProfile Object123_Profile;

