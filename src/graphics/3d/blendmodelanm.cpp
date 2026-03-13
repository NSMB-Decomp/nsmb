#include "blendmodelanm.hpp"

BlendModelAnm::BlendModelAnm() {

	for (int i = 0; i < 2; i++) {
		blendAnims[i].animation = nullptr;
		blendAnims[i].attached = false;
	}

	currentAnimID = 0;
	lastAnimID = 0;
	selector1 = 0;
	selector2 = 0;
	frameController.currentFrame = 0;
	frameController.speed = 0x1000;
	blendRatio = 0x1000;

}

BlendModelAnm::~BlendModelAnm() {}

void BlendModelAnm::render(const Vec3_32s* scale) {

	Ns3dAnimation* anim1 = blendAnims[selector1].animation;
	Ns3dAnimation* anim2 = blendAnims[selector2].animation;

	Ns_3dAnimationSetFrame(anim1, frameController.currentFrame);
	Ns_3dAnimationSetRatio(anim1, blendRatio);
	Ns_3dAnimationSetRatio(anim2, 0x1000 - blendRatio);

	Model::render(scale);

}

void BlendModelAnm::render(const Mat4x3& transform, const Vec3_32s* scale) {

	Ns3dAnimation* anim1 = blendAnims[selector1].animation;
	Ns3dAnimation* anim2 = blendAnims[selector2].animation;

	Ns_3dAnimationSetFrame(anim1, frameController.currentFrame);
	Ns_3dAnimationSetRatio(anim1, blendRatio);
	Ns_3dAnimationSetRatio(anim2, 0x1000 - blendRatio);

	Model::render(transform, scale);

}

void BlendModelAnm::render() {

	Ns3dAnimation* anim1 = blendAnims[selector1].animation;
	Ns3dAnimation* anim2 = blendAnims[selector2].animation;

	Ns_3dAnimationSetFrame(anim1, frameController.currentFrame);
	Ns_3dAnimationSetRatio(anim1, blendRatio);
	Ns_3dAnimationSetRatio(anim2, 0x1000 - blendRatio);

	Model::render();

}

bool BlendModelAnm::create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID) {

	int i;
	Ns3dAnimationData* animData;

	if (!Model::create(bmd, modelID, polygonID))
		return false;

	animFile = bca;
	if (!animFile)
		return false;

	animData = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), animID);
	if (!animData)
		return false;

	u32 animSize = Ns_3dAnimationGetSize(animData, model);

	for (i = 0; i < 2; i++) {

		u8* animBuff = new u8[animSize];

		blendAnims[i].animation = rcast<Ns3dAnimation*>(animBuff);
		if (!blendAnims[i].animation)
			return false;

		Ns_3dAnimationInit(blendAnims[i].animation, animData, model, nullptr);

	}

	currentAnimID = animID;

	frameController.init(animData->frameCount, FrameCtrl::Looping, 0x1000, 0);
	attachAnimation(&blendAnims[selector1]);

	return true;

}

void BlendModelAnm::pushAnimation(u32 animID, u32 steps, u32 type, i32 speed, u16 startFrame) {

	if (currentAnimID == animID) {
		frameController.setAnimationType(type);
		frameController.speed = speed;
		return;
	}

	if (lastAnimID == animID && blendRatio != 0x1000) {
		blendRatio = Ns_3dAnimationGetRatio(blendAnims[selector2].animation);
	} else {
		blendRatio = 0;
	}

	lastAnimID = currentAnimID;
	currentAnimID = animID;

	selector2 = selector1;
	selector1 = (selector1 + 1) & 1;

	detachAnimation(&blendAnims[selector1]);

	Ns3dAnimationData* animData = Ns_3dGetAnimation(scast<Ns3dFileHeader*>(animFile), animID);
	// TODO: no nullptr check?

	Ns_3dAnimationInit(blendAnims[selector1].animation, animData, model, nullptr);
	frameController.init(animData->frameCount, type, speed, startFrame);
	attachAnimation(&blendAnims[selector1]);

	if ((int)steps <= 0) {
		blendRatio = 0x1000;
		detachAnimation(&blendAnims[selector2]);
		return;
	}

	blendStep = FixedDiv(0x1000, (steps + 1) * 0x1000);
	Ns_3dAnimationSetRatio(blendAnims[selector1].animation, blendRatio);
	Ns_3dAnimationSetRatio(blendAnims[selector2].animation, 0x1000 - blendRatio);

}

void BlendModelAnm::update() {

	frameController.update();

	if (blendRatio < 0x1000) {
		blendRatio += blendStep;

		if (blendRatio >= 0x1000) {
			blendRatio = 0x1000;
			detachAnimation(&blendAnims[selector2]);
		}
	}

}

void BlendModelAnm::attachAnimation(BlendAnimation* anim) {
	Ns_3dDrawableAttachAnimation(&drawable, anim->animation);
	anim->attached = true;
}

void BlendModelAnm::detachAnimation(BlendAnimation* anim) {

	if (anim->attached) {
		Ns_3dDrawableDetachAnimation(&drawable, anim->animation);
		anim->attached = false;
	}

}
