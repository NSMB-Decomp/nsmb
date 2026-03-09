#pragma once
#include "Nitro.hpp"

namespace G3D {

	// 02019B6C
	void initialize(); // Initializes the graphics engine

	// 02019B78
	void shutdown(); // Does nothing

	// 02019AFC
	bool getTextureParams(Ns3dTextureData* texture, u32 texID, u32& texParams); // Obtains the texture's parameters and stores them in texParams. returns whether texture params were fetched successfully.

	// 02019A88
	bool getPaletteParams(Ns3dTextureData* texture, u32 palID, u32& palParams); // Calculates the palettes's VRAM slot destination address and stores it in palParams. returns whether address calculation was successful.

}
