#include "model.hpp"

Model::Model() {
	model = nullptr;
	texture = nullptr;
}

Model::~Model() {}


bool Model::create(void* bmd, u32 modelID, u32 polygonID) {

	model = loadModel(bmd, modelID, &texture);
	if (!model)
		return false;

	Ns_3dDrawableInit(&drawable, model);
	Ns_3dDrawableSetUserData(&drawable, nullptr);

	Ns_3dModelSetAllPolygonID(model, polygonID);
	Ns_3dModelUseGlobalAmbient(model);
	Ns_3dModelUseGlobalEmission(model);

	return true;

}

void Model::null() {}

void Model::renderModel() {
	Ns_3dDrawableDraw(&drawable);
}

void Model::flush() const {
	Ns_3dFlush();
}

void Model::render(const Vec3_32s* scale) {

	Ns_3dSetRotation(rcast<const Mat3x3*>(&matrix));
	Ns_3dSetTrans(rcast<const Vec3_32s*>(matrix.v[3]));

	if (scale)
		Ns_3dSetScale(scale);

	flush();
	renderModel();

}

void Model::render(const Mat4x3& transform, const Vec3_32s* scale) {

	Ns_3dSetRotation(rcast<const Mat3x3*>(&transform));
	Ns_3dSetTrans(rcast<const Vec3_32s*>(transform.v[3]));

	if (scale)
		Ns_3dSetScale(scale);

	flush();
	renderModel();

}

void Model::render() {
	renderModel();
}

void Model::setCommandCallback(Ns3dCmdFunc func, u8* address, u8 cmd, u32 timing) {
	Ns_3dDrawableSetCmdFunc(&drawable, func, address, cmd, timing);
}

Ns3dMaterialData* Model::getMaterialData(u32 index) {
	return Ns_3dGetMaterial(Ns_3dGetMaterials(model), index);
}

Ns3dMaterialList* Model::getMaterialCollection() {
	return Ns_3dGetMaterials(model);
}

i32 Model::getMaterialIndex(const Ns3dStringData* name) {
	Ns3dMaterialList* mats = getMaterialCollection();
	return Ns_3dGetDictionaryIndex(&mats->dict, name);
}

Ns3dNodeList* Model::getNodeInfo() {
	return Ns_3dGetNodes(model);
}

i32 Model::getNodeIndex(const Ns3dStringData* name) {
	Ns3dNodeList* nodes = getNodeInfo();
	return Ns_3dGetDictionaryIndex(&nodes->dict, name);
}

bool Model::getNodeMatrixInternal(Ns3dNodeList* nodeInfo, u32 nodeIndex, Mat4x3* mtx) {

	Ns3dNodeData* nodeData = Ns_3dGetNode(nodeInfo, nodeIndex);

	u32 matrixStackIndex = (nodeData->flags & NS_3D_NODE_MTX_INDEX_MASK) >> NS_3D_NODE_MTX_INDEX_SHIFT;
	if (matrixStackIndex == 31)
		return false;

	Ns_3dRestoreMatrix(matrixStackIndex);
	Ns_3dGetCurrentMatrices(mtx, nullptr);
	ConcatMat4x3(mtx, Ns_3dGetInvCameraMatrix(), mtx);

	return true;

}

bool Model::getNodeMatrix(u32 nodeIndex, Mat4x3* mtx) {
	return getNodeMatrixInternal(Ns_3dGetNodes(model), nodeIndex, mtx);
}

bool Model::getNodePosition(u32 nodeIndex, Vec3_32& position) {

	Mat4x3 mtx;

	if (getNodeMatrixInternal(Ns_3dGetNodes(model), nodeIndex, &mtx)) {

		// Works
		/* i32 z = mtx.m32;
		i32 y = mtx.m31;
		i32 x = mtx.m30;
		position.x = x;
		position.y = y;
		position.z = z; */

		position.setFromMat4x3(mtx);

		// Nope, stack too big (0x40 instead of 0x30)
		//position = Vec3_32(mtx.m30, mtx.m31, mtx.m32);

		// Same
		//position = *rcast<Vec3_32s*>(&mtx.m30);

		return true;

	}

	return false;

}

bool Model::restoreNodeMatrix(u32 nodeIndex) {

	Ns3dNodeData* nodeData = Ns_3dGetNode(Ns_3dGetNodes(model), nodeIndex);

	u32 matrixStackIndex = (nodeData->flags & NS_3D_NODE_MTX_INDEX_MASK) >> NS_3D_NODE_MTX_INDEX_SHIFT;
	if (matrixStackIndex == 31)
		return false;

	Ns_3dRestoreMatrix(matrixStackIndex);
	return true;

}