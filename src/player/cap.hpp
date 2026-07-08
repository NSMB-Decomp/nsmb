#pragma once
#include "anim.hpp"
#include "../graphics/3d/animation.hpp"
#include "../graphics/3d/model.hpp"

// vtable at 0212F8B0 (ov11)
class PlayerCap {
public:

	PlayerCap();
	virtual ~PlayerCap();

	bool create(u8 playerID);
	bool render(BOOL skip, i32 frame, i8 texPalette, u16 diffuse, u16 ambient, BOOL toon);
	void setAnimation(u8 animType, BOOL smallPlayer);

	static bool loadResources();

	static u16 paletteParams[2];
	static u32 textureParams[2];

	static u32 modelFileIDs[2];
	static u16 paletteOffsets[4];
	static PlayerCapAnimation capAnimations[9];


	Model model;
	Animation animation;
	FrameCtrl frameController;
	u8 playerID;
	i8 animType;

};
NTR_SIZE_GUARD(PlayerCap, 0xC4);
