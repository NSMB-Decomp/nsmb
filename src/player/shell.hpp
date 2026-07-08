#pragma once
#include "../graphics/3d/model.hpp"

// vtable at 0212F8C0 (ov11)
class PlayerShell {
public:

	PlayerShell();
	virtual ~PlayerShell();

	bool create();
	bool render(BOOL skip, i8 texPalette, u16 diffuse, u16 ambient, BOOL toon);

	static bool loadResources();

	static u16 paletteParams;
	static u32 textureParams;


	Model model;

};
NTR_SIZE_GUARD(PlayerShell, 0x94);
