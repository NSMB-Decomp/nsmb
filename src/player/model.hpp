#pragma once
#include "anim.hpp"
#include "cap.hpp"
#include "shell.hpp"

enum ModelState { MS_Super, MS_Small };

enum HeadState { HS_Cap, HS_NoCap, HS_Dead, HS_DeadNoCap };

enum Flags { F_None = 0, F_Unused = 0x1, F_RenderSeparateCap = 0x2, F_RenderNoCapHead = 0x4, F_RenderDeadHead = 0x8, F_RenderShell = 0x10 };

struct ModelCollection {
	Model *body;
	Model *heads[4];
};

union NodeTransforms {
	struct _ {
		Mat4x3 rightWrist; // Bone: wrist_r1
		Mat4x3 leftWrist;  // Bone: wrist_l1
		Mat4x3 rightAnkle; // Bone: ankle_r1
		Mat4x3 leftAnkle;  // Bone: ankle_l1
		Mat4x3 face;	   // Bone: face_1
		Mat4x3 body;	   // Bone: spin
		Mat4x3 leftArm;	   // Bone: arm_l2
		Mat4x3 rightArm;   // Bone: arm_r2
		Mat4x3 leftLeg;	   // Bone: leg_l2
		Mat4x3 rightLeg;   // Bone: leg_r2
	} s;
	Mat4x3 m[10];
};

class PlayerModel
{
      public:
	PlayerModel();
	virtual ~PlayerModel();

	bool create(u8 playerID, u32 animationFileID);
	bool loadBody(u32 animationFileID);
	bool loadHead();
	void setBodyModelCallback(void *callback);
	void setBodyModelOwner(void *owner);

	void render(Mat4x3 &bodyModelMatrix, Vec3_32 &scale, i8 texPalette, BOOL skip, u32 diffuse, u32 ambient, BOOL toon);
	void enableBodyToon(Model &model);
	void enableHeadToon(Model &model);
	void disableBodyToon(Model &model);
	void disableHeadToon(Model &model);
	void setDeathTexImageParams(); // TODO: what does this actually do?

	void setBodyAnimation(void *anmResource, u32 blendSteps, u32 type, i32 speed, u16 startFrame);
	void switchBodyAnimations(u32 sourceModel, u32 targetModel);
	void setHeadAnimation(void *anmResource, u32 type, i32 speed, u16 startFrame);
	void update();
	bool animationFinished();
	void setCurrentAnimationFrame(u16 frame);
	u16 getCurrentAnimationFrame() const;
	i32 getFullAnimationFrame() const;
	u16 getAnimationFrameCount() const;
	void setAnimationSpeed(i32 speed);
	i32 getAnimationSpeed() const;
	bool animationPassing(u16 targetFrame) const;
	void initPartialAnimation(void *anmResource, u32 type, i32 speed, u16 startFrame);
	void startPartialAnimation(u32 nodeDisableIndex);
	void endPartialAnimation();
	void updatePartialAnimation();
	void saveNodeTransforms();

	static PlayerHeadAnimation luigiHeadAnimations[9];
	static PlayerHeadAnimation marioHeadAnimations[9];
	static u32 bodyModelIDs[2];
	static u16 bodyPaletteOffsets[4];
	static u16 headPaletteOffsets[4]; // For head + cap
	static u32 bodyModelFileIDs[2];
	static u32 capHeadPaletteSlots[2][2];
	static u32 bodyPaletteSlots[2][2];
	static u32 deadHeadPaletteSlots[2][2];
	static u32 headModelIDs[2][2];
	static u32 headModelFileIDs[2][4];
	static u32 headPatternFileIDs[2];
	static PlayerHeadAnimation *headAnimations[2];
	static u32 deadBodyTextureSlots[2][2];
	static u32 deadHeadTextureSlots[2][2][4];

	void *currentBodyAnmResource;	      // Current body animation resource
	void *lastBodyAnmResource;	      // Last body animation resource
	void *partialBodyAnmResource;	      // Partial body animation resource
	Ns3dAnimation *bodyAnimations[2];     // Blending body animations
	Ns3dAnimation *partialBodyAnimation;  // Partial body animation
	u16 *bodyAnimationMapData;	      // Initial body map data (bone -> model node)
	void *headAnmResource;		      // Head animation resource
	Ns3dAnimation *headAnimation;	      // Head animation
	FrameCtrl bodyFrameController;	      // Body frame controller
	FrameCtrl partialBodyFrameController; // Partial frame controller
	ModelCollection models[2];	      // Super and small models
	FrameCtrl headFrameController;	      // Head frame controller
	PlayerCap cap;			      // Player cap (not attached to body/head)
	PlayerShell shell;		      // Player shell
	NodeTransforms nodeTransforms;	      // Node transforms of certain bones
	i32 bodyAnmBlendRatio;		      // Body animation blend ratio (between 0.0 and 1.0)
	i32 bodyAnmBlendStep;		      // Body animation step (increments the ratio per step)
	u32 activeAnimationIndex;	      // Active body animation index (into bodyAnimations)
	u32 animationNodeDisableIndex;	      // Node index determining partial animation boundaries: 0->(ANDI-1)=disables partial nodes; ANDI->(node count-1)=disables body nodes
	u32 partialBodyActive;		      // 1 if partial animation is active, else 0
	u8 playerID;			      // Player ID
	u8 modelState;			      // Model state
	u8 headState;			      // Head state
	u8 flags;			      // Render flags
};
size_assert(PlayerModel, 0x3C4);