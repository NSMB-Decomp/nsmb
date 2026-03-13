#include "util.hpp"

namespace G3D {

	void initialize() {
		// Initialize 3D framework
		Ns_3dInitialize();
	}

	void shutdown() {
		// Do nothing
	}

	bool getTextureParams(Ns3dTextureData* texture, u32 texID, u32& texParams) {

		Ns3dTexImageData* texData = Ns_3dGetTexImageData(texture, texID);
		if (texData) {

			u32 offset;
			if ((texData->textureParam & (0x7 << 26)) != (TEX_FMT_COMP4x4 << 26)) {
				offset = texture->textureVramOffset & 0xFFFF;
			} else {
				offset = texture->comp4x4VramOffset & 0xFFFF;
			}

			texParams = texData->textureParam + offset;

			return true;
		}

		return false;

	}

	bool getPaletteParams(Ns3dTextureData* texture, u32 palID, u32& palParams) {

		Ns3dTexPaletteData* palData = Ns_3dGetTexPaletteData(texture, palID);
		if (palData) {

			u32 offset = texture->paletteVramOffset & 0xFFFF;
			u16 param = palData->paletteParam;

			if ((palData->_4 & 1) == 0) {
				offset >>= 1;
				param >>= 1;
			}

			palParams = param + offset;

			return true;
		}

		return false;

	}

}
