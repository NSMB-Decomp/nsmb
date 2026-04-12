#pragma once
#include "model.hpp"
#include "../util/framectrl.hpp"

//vtable 0203c4fc
class ModelAnm : public Model {
public:

	FrameCtrl frameController;
	void* animFile; //Animation file ptr
	Ns3dAnimation* animation;
	u32 animID; //Anim ID

	//02019644
	ModelAnm();

	//D0:020195fc
	//D1:02019624
	virtual ~ModelAnm();

	//02019518
	virtual void render(const Vec3_32s* scale);

	//020194f8
	virtual void render(const Mat4x3& transform, const Vec3_32s* scale);

	//020194e0
	virtual void render();

	//02019530
	bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID); //Loads the model from bmd and the animation from bca. Also allocates unka0 on heap. Default initializes the frame animation. Attaches the animation to the render object. returns true if successful, false otherwise.

	//02019440
	void init(u32 animID, u32 type, i32 speed, u16 startFrame); //If animID equals the current animation ID, type and speed are applied to the frame controller. If not, the animation object is reset and is initialized with the given parameters.


	inline void update() {
		frameController.update();
	}

	inline bool finished() {
		return frameController.finished();
	}

	inline void setFrame(u16 frame) {
		frameController.setFrame(frame);
		Ns_3dAnimationSetFrame(animation, frame << 12);
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
size_assert(ModelAnm, 0xA8);
