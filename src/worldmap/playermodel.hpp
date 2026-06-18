#pragma once
#include "../player/model.hpp"
#include "../graphics/3d/modelanm.hpp"
#include "../graphics/3d/animationctrl.hpp"

class WmPlayerModel {
public:

	enum Powerup {
		Small,
		Super,
		Fire,
		Mini,
		Shell
	};

	struct Config {
		s8 modelState;
		s8 paletteID;
	};

	virtual ~WmPlayerModel();


	PlayerModel model;
	Config* config;
	u32 animID;
	u32 headAnimID;
	s8 playerID;
	s8 modelState;
	s8 powerup;

};
size_assert(WmPlayerModel, 0x3D8);
