#pragma once
#include "Nitro.hpp"

struct TextureInfo {

	u32 textureParams;
	u32 paletteParams;

};

//vtable 0203c49c
class Texture
{
public:

	//02018c2c
	Texture();

	//D0:02018bfc
	//D1:02018c1c
	virtual ~Texture();

	//02018bc8
	bool load(void* texFile); //Loads the texture from the file. returns true if successful, false otherwise.

	//02018b98
	bool getTextureParams(u32& texParams, u32 texID); //Calls GFX::getTextureParams and returns whether parameter fetching was successful.

	//02018b68
	bool getPaletteParams(u32& palParams, u32 palID); //Calls GFX::getTexturePaletteDestination and returns whether address calculation was successful.


	Ns3dTextureData* texture;

};
size_assert(Texture, 0x8);
