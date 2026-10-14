#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 146  |  ov025  |  profile @ 0x02141ce4
class Object146 : public StageEntity {
public:
	ModelAnm _3f4;  // 0x3f4
	u8 _pad0[0x10];
	
	static void *create();
	inline Object146() {};
	inline ~Object146() {};
};

extern ActorProfile Object146_Profile;

