#include "modelanm.hpp"

ModelAnm::ModelAnm() {

	animation = nullptr;
	animID = 0;

	frameController.currentFrame = 0;
	frameController.speed = 0x1000;

}

ModelAnm::~ModelAnm() {}

bool ModelAnm::create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID) {

	if (!Model::create(bmd, modelID, polygonID))
		return false;

	animFile = bca;
	if (!animFile)
		return false;

	Ns3dAnimationData* animData = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), animID);
	if (!animData)
		return false;

	u32 animSize = Ns_3dAnimationGetSize(animData, data);
	u8* animBuff = new u8[animSize];

	animation = rcast<Ns3dAnimation*>(animBuff);
	if (!animation)
		return false;

	this->animID = animID;

	Ns_3dAnimationInit(animation, animData, data, nullptr);
	frameController.init(animData->frameCount, FrameCtrl::Looping, 0x1000, 0);
	Ns_3dDrawableAttachAnimation(&drawable, animation);

	return true;

}

void ModelAnm::render(const Vec3_32s* scale) {

	Ns_3dAnimationSetFrame(animation, frameController.currentFrame);

	Model::render(scale);

}

void ModelAnm::render(const Mat4x3& transform, const Vec3_32s* scale) {

	Ns_3dAnimationSetFrame(animation, frameController.currentFrame);

	Model::render(transform, scale);

}

void ModelAnm::render() {

	Ns_3dAnimationSetFrame(animation, frameController.currentFrame);

	Model::render();

}

void ModelAnm::init(u32 animID, u32 type, i32 speed, u16 startFrame) {

	if (this->animID == animID) {
		frameController.setAnimationType(type);
		frameController.speed = speed;
		return;
	}

	Ns_3dDrawableDetachAnimation(&drawable, animation);

	this->animID = animID;

	Ns3dAnimationData* animData = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), animID);
	// TODO: no nullptr check?

	Ns_3dAnimationInit(animation, animData, data, nullptr);
	frameController.init(animData->frameCount, type, speed, startFrame);
	Ns_3dDrawableAttachAnimation(&drawable, animation);

}
