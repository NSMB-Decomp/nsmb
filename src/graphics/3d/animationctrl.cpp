#include "animationctrl.hpp"

AnimationCtrl::AnimationCtrl() {}

AnimationCtrl::~AnimationCtrl() {}


bool AnimationCtrl::createCtrl(Ns3dDrawable* drw, void* file, u32 animID, Ns3dTextureData* tex) {

	if (!Animation::create(drw, file, animID, tex))
		return false;

	frameController.init(frameCount, FrameCtrl::Looping, 0x1000, 0);
	return true;

}

void AnimationCtrl::init(u32 animID, u32 type, i32 speed, u16 startFrame) {

	if (animID == this->animID) {
		frameController.setAnimationType(type);
		frameController.speed = speed;
		return;
	}

	detach();

	if (reset(animID)) {
		attach();
	}

	frameController.init(frameCount, type, speed, startFrame);

}

void AnimationCtrl::update() {

	frameController.update();
	Ns_3dAnimationSetFrame(animation, frameController.currentFrame);

}

void AnimationCtrl::setFrame(u16 frame) {

	frameController.setFrame(frame);
	Ns_3dAnimationSetFrame(animation, frameController.currentFrame);

}
