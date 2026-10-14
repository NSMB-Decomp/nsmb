#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 35  |  ov042  |  profile @ 0x02152460
class Object35 : public StageEntity {
public:
	ModelAnm _3f4;  // 0x3f4
	u8 _pad0[0x20];
	
	static void *create();
	inline Object35() {};
	inline ~Object35() {};
};

extern ActorProfile Object35_Profile;

