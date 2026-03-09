#include "modelbase.hpp"

ModelBase::ModelBase() {}

ModelBase::~ModelBase() {}


Ns3dModelData* ModelBase::loadModel(void* bmd, u32 modelID, Ns3dTextureData** texture) {

	if (bmd == nullptr)
		return nullptr;

	Ns3dModelList* mdlList = Ns_3dGetModelList(rcast<Ns3dFileHeader*>(bmd));
	Ns3dModelData* mdl = Ns_3dGetModel(mdlList, modelID);

	*texture = Ns_3dGetTexture(rcast<Ns3dFileHeader*>(bmd));
	return mdl;

}