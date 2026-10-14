#pragma once
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 96  |  ov034  |  profile @ 0x02145200
class Object96 : public StageEntity {
public:
	ModelAnm _3f4;
	u8 _pad0[0x1c];
	
	static void *create();
	inline Object96() {};
	inline ~Object96() {};
};

extern ActorProfile Object96_Profile;

