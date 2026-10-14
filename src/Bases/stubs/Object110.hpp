#pragma once
#include "../../graphics/3d/animation.hpp"
#include "../../graphics/3d/animationctrl.hpp"
#include "../../graphics/3d/model.hpp"
#include "../../graphics/3d/modelanm.hpp"
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 110  |  ov068  |  profile @ 0x02179420
class Object110 : public StageEntity {
public:
	ModelAnm _3f4;
	Model _49c;
	AnimationCtrl _52c;
	Animation _558;
	u8 _pad0[0x2c];

	static void *create();
	inline Object110() {};
	inline ~Object110() {};
};

extern ActorProfile Object110_Profile;

