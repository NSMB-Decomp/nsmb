#pragma once
#include "model.hpp"
#include "../util/framectrl.hpp"

//vtable 0203c4dc
class BlendModelAnm : public Model
{
public:

	struct BlendAnimation {
		Ns3dAnimation* animation;
		bool attached;//True if the animation object is attached to the render object
	};

	FrameCtrl frameController;
	void* animFile; //Anim file ptr
	BlendAnimation blendAnims[2];
	u32 currentAnimID; //Current animation ID
	u32 lastAnimID; //Last animation ID
	i32 blendRatio; //Blend ratio
	i32 blendStep; //Blend increment
	i8 selector1; //Selector 1 (start interpolation)
	i8 selector2; //Selector 2 (end interpolation) [c1->c0]

	//020193e0
	BlendModelAnm();

	//D0:020193c0
	//D1:020193c0
	virtual ~BlendModelAnm() override;

	//02019214
	virtual void render(const Vec3_32s* scale) override;

	//020191cc
	virtual void render(const Mat4x3& transform, const Vec3_32s* scale) override;

	//0201918c
	virtual void render() override;

	//020192a8
	bool create(void* bmd, void* bca, u32 modelID, u32 animID, u32 polygonID); //Loads the model with the given params from the bmd. Allocates memory for both BlendAnimations, initializes the frame controller and registers the first animation. returns true if successful, false otherwise.

	//02018fb8
	void pushAnimation(u32 animID, u32 steps, u32 type, i32 speed, u16 startFrame);
	/*
		Pushes a new animation to blend to.
		If animID equals the current animation's ID, frame controller settings are applied only.
		If animID equals the last animation's ID which is not fully back-blended, the animation is blended back to itself.
		If animID is a new animation ID, the animation including the frame controller is initialized. It resets the blend ratio to 0 and calculates the blend increment with 1 / (steps + 1).
	*/

	//02019138
	void update(); //Updates the frame controller and increments the blend ratio. If the ratio exceeds 1.0 after update, it is capped at 1.0 and unregisters the animation.

	//02019288
	void attachAnimation(BlendAnimation* anim); //If it's active, unregister it from the model and deactivate it

	//0201925c
	void detachAnimation(BlendAnimation* anim); //Register anim for the model and activate it

};
size_assert(BlendModelAnm, 0xC4);
