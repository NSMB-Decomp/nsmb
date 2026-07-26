#pragma once

#include "../../src/base_types.hpp"

union Mat2x2;
union Mat4x3;
union Mat4x4;
struct Vec3_32s;
struct Ns3dModelData;

namespace NDS {

namespace Graphics3D {

bool setupResource(void *resource);
void *getTexture(void *resource);
void buildLookAtMatrix(const Vec3_32s *position, const Vec3_32s *up,
	const Vec3_32s *target, BOOL applyToHardware, Mat4x3 *matrix);
void buildPerspectiveMatrix(fx32 sine, fx32 cosine, fx32 aspect,
	fx32 nearDistance, fx32 farDistance, fx32 scale,
	BOOL applyToHardware, Mat4x4 *matrix);
void setLightVector(u32 lightID, s16 x, s16 y, s16 z);
void setLightColor(u32 lightID, u32 color);
void setMaterialDiffuseAmbient(u32 diffuse, u32 ambient, BOOL useVertexColor);
void setMaterialSpecularEmission(u32 specular, u32 emission, BOOL shininess);
void setPolygonAttributes(u32 lightMask, u32 polygonMode, u32 cullMode,
	u32 polygonID, u32 alpha, u32 depth);
void setModelAlpha(Ns3dModelData *model, u32 materialID, u32 alpha);
void setModelAlphaAll(Ns3dModelData *model, u32 alpha);

}

namespace Graphics {

void setMainDisplayMode(u32 displayMode, u32 backgroundMode, u32 backgroundZeroMode);
u32 setSubDisplayMode(u32 backgroundMode);
void setMasterBrightness(void *registerAddress, s32 brightness);
void signalVerticalBlank(BOOL enabled);
void signalHorizontalBlank(BOOL enabled);

void disableMainBackgroundBank();
void disableMainObjectBank();
void disableMainBackgroundPaletteBank();
void disableMainObjectPaletteBank();
void disableTextureBank();
void disableTexturePaletteBank();
void disableClearImageBank();
void disableArm7Bank();
void disableLcdcBank();
void disableSubBackgroundBank();
void disableSubObjectBank();
void disableSubBackgroundPaletteBank();
void disableSubObjectPaletteBank();

void resetMainBackgroundBank();
void resetMainObjectBank();
void resetMainBackgroundPaletteBank();
void resetMainObjectPaletteBank();
void resetTextureBank();
void resetTexturePaletteBank();
void resetClearImageBank();
void resetSubBackgroundBank();
void resetSubObjectBank();
void resetSubBackgroundPaletteBank();
void resetSubObjectPaletteBank();

void assignMainBackgroundBank(u32 banks);
void assignMainObjectBank(u32 banks);
void assignMainBackgroundPaletteBank(u32 banks);
void assignMainObjectPaletteBank(u32 banks);
void assignTextureBank(u32 banks);
void assignTexturePaletteBank(u32 banks);
void assignLcdcBank(u32 banks);
void assignSubBackgroundBank(u32 banks);
void assignSubObjectBank(u32 banks);

u32 mainBackground0Map();
void *subBackground0Map();
u32 mainBackground1Map();
u32 mainBackground2Map();
u32 mainBackground3Map();
void *subBackground0Tiles();
u32 subBackground1Map();
u32 subBackground2Map();
u32 subBackground3Map();
u32 mainBackground0Tiles();
u32 mainBackground1Tiles();
void *mainBackground2Tiles();
u32 mainBackground3Tiles();
void *subBackground1Tiles();
u32 subBackground2Tiles();
u32 subBackground3Tiles();

void applyAffine2D(void *registers, const Mat2x2 *matrix,
	s32 centerX, s32 centerY, s32 offsetX, s32 offsetY);
u32 uploadSubBackgroundPalette(u32 source, u32 offset, u32 size);
u32 uploadMainBackgroundPalette(u16 *source, u32 offset, u32 size);
void beginMainBackgroundExtendedPaletteUpload();
void uploadMainBackgroundExtendedPalette(void *source, u32 offset, u32 size);
void endMainBackgroundExtendedPaletteUpload();
void beginMainObjectExtendedPaletteUpload();
void uploadMainObjectExtendedPalette(void *source, u32 offset, u32 size);
void endMainObjectExtendedPaletteUpload();
void uploadMainObjectPalette(void *source, u32 offset, u32 size);

void flushGeometry();
void initializeInterruptTable();
void enableDisplays();
void setFogTable(const u32 *table);
void configureFog(BOOL enabled, u32 alpha, u32 depthShift, u32 offset);

inline void setClearImageOffset(u32 packedOffset)
{
	*reinterpret_cast<volatile u32 *>(0x04000358) = packedOffset;
}

inline void swapBuffers(u32 sortMode, u32 bufferMode)
{
	*reinterpret_cast<volatile u32 *>(0x04000540) = (sortMode << 1) | bufferMode;
}

}
}
