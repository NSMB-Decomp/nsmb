#pragma once
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 54  |  ov068  |  profile @ 0x02179180
class Object54 : public StageEntity {
public:
	ModelAnm _3f4;
	Model _49c;
	u8 _pad0[0x58];
	static void *create();
	inline Object54() {};
	inline ~Object54() {};
};

extern ActorProfile Object54_Profile;

