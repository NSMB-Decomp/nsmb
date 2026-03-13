#pragma once
#include "animation.hpp"
#include "../util/framectrl.hpp"

//vtable 0203c4cc
class AnimationCtrl : public Animation
{
public:

	FrameCtrl frameController;

	//02018d88
	AnimationCtrl();

	//D0:02018d40
	//D1:02018d68
	virtual ~AnimationCtrl();

	//02018cf4
	bool createCtrl(Ns3dDrawable* drw, void* file, u32 animID, Ns3dTextureData* tex); //Creates the animation and sets up the frame controller with the given parameters. returns true if successful, false otherwise.

	//02018c74
	void init(u32 animID, u32 type, i32 speed, u16 startFrame); //If animID doesn't equal the current animation ID, the new animation is loaded and attached if successful. In both cases the frame controller is reinitialized with type and speed, startFrame is only set when the animation ID changed.

	//02018c54
	void update(); //Steps the frame controller and updates the animation accordingly

	//02018c3c
	void setFrame(u16 frame); //Sets the animation's frame and updates it accordingly

	inline bool finished() {
		return frameController.finished();
	}

	inline u16 getFrame() {
		return frameController.currentFrame >> 12;
	}

	inline void setFullFrame(i32 frame) {
		frameController.currentFrame = frame;
	}

	inline i32 getFullFrame() {
		return frameController.currentFrame;
	}

	inline void setFrameCount(u16 count) {
		frameController.setFrameCount(count);
	}

	inline u16 getFrameCount() {
		return frameController.getFrameCount();
	}

	inline void setSpeed(i32 speed) {
		frameController.speed = speed;
	}

	inline i32 getSpeed() {
		return frameController.speed;
	}

};
size_assert(AnimationCtrl, 0x2C);
