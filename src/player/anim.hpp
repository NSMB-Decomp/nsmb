#pragma once
#include "../graphics/util/framectrl.hpp"

struct PlayerCapAnimation {

	u32 marioAnimID;
	u32 marioSmallAnimID;
	u32 luigiAnimID;
	u32 luigiSmallAnimID;
	u32 type;
	i32 speed;
	u16 startFrame;

};

struct PlayerHeadAnimation {

	u32 animID;
	u32 type;
	i32 speed;
	u16 startFrame;

};
