#include "animation.hpp"

Animation::Animation() {
	drawable = nullptr;
	model = nullptr;
	texture = nullptr;
	animFile = nullptr;
	animation = nullptr;
}

Animation::~Animation() {}


bool Animation::create(Ns3dDrawable* drw, void* file, u32 animID, Ns3dTextureData* tex) {

	animFile = file;
	if (!animFile)
		return false;

	Ns3dAnimationData* animData = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), animID);
	if (!animData)
		return false;

	this->drawable = drw;
	this->model = drw->modelData;
	this->texture = tex;

	u32 animSize = Ns_3dAnimationGetSize(animData, model);
	u8* animBuff = new u8[animSize];

	animation = rcast<Ns3dAnimation*>(animBuff);
	if (!animation)
		return false;

	this->animID = animID;

	Ns_3dAnimationInit(animation, animData, model, texture);
	frameCount = animData->frameCount;
	Ns_3dDrawableAttachAnimation(drawable, animation);

	return true;

}

void Animation::init(u32 animID, u16 startFrame) {

	if (animID != this->animID) {

		detach();

		if (reset(animID)) {
			attach();
		}

	}

	Ns_3dAnimationSetFrame(animation, startFrame * 4096);

}

bool Animation::reset(u32 animID) {

	this->animID = animID;

	Ns3dAnimationData* animData = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), animID);
	if (!animData)
		return false;

	Ns_3dAnimationInit(animation, animData, model, texture);
	frameCount = animData->frameCount;

	return true;

}

void Animation::attach() {
	Ns_3dDrawableAttachAnimation(drawable, animation);
}

void Animation::detach() {
	Ns_3dDrawableDetachAnimation(drawable, animation);
}