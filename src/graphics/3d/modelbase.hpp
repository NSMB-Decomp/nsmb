#pragma once
#include "../../nsmb_nitro.hpp"

class ModelBase {
public:

	ModelBase();

	virtual ~ModelBase();


	static Ns3dModelData* loadModel(void* bmd, u32 modelID, Ns3dTextureData** texture);


	Ns3dDrawable drawable;

};
NTR_SIZE_GUARD(ModelBase, 0x58);
