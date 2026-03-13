#include "texture.hpp"
#include "util.hpp"

Texture::Texture() {}

Texture::~Texture() {}


bool Texture::load(void* texFile) {

	if (!texFile)
		return false;

	texture = Ns_3dGetTexture(scast<Ns3dFileHeader*>(texFile));
	return texture != nullptr;

}

bool Texture::getTextureParams(u32& texParams, u32 texID) {
	return G3D::getTextureParams(texture, texID, texParams) != false;
}

bool Texture::getPaletteParams(u32& palParams, u32 palID) {
	return G3D::getPaletteParams(texture, palID, palParams) != false;
}
