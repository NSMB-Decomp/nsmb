#pragma once
#include "Nitro.hpp"

class ModelBase {
public:

	ModelBase();

	virtual ~ModelBase();


	static Ns3dModelData* loadModel(void* bmd, u32 modelID, Ns3dTextureData** texture);


	Ns3dDrawable drawable;

};
size_assert(ModelBase, 0x58);
