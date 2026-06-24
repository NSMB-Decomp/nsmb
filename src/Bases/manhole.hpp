#pragma once
#include "StageEntity.hpp"
#include "../graphics/graphics3d.hpp"

class Manhole : public StageEntity {
public:

	enum CollisionKind {
		CK_None,
		CK_Player,
		CK_GroundPound,
	};

	// The argument is unused
	typedef bool(Manhole::* StateFunction)(u32);

	s32 onCreate();
	s32 onRender();
	s32 onDestroy();
	bool onPrepareResources();

	bool updateMain() override;

	bool switchState(StateFunction function, u32 arg);
	void updateState(u32 arg);

	bool solidIdle(u32 arg);
	bool rollForward(u32 arg);
	bool rollBackward(u32 arg);

	void updateRollingSound();
	CollisionKind getPlatformCollision();

	static bool loadResources();
	static void activeCallback(ActiveCollider& self, ActiveCollider& other);
	static void *create();

	static ObjectInfo objectInfo;
	static ActorProfile profile;
	static const AcConfig acConfig;

	StateFunction updateFunction;
	Model model;
	RotatingPlatform platform;

	fx32 roll;
	u16 rollAngle;
	u16 rollAmplitude;
	s16 lastRotationX;

	s8 updateStep;

	bool playerJumping;
	bool playerGroundPounding;
	u8 rollTimer;
	bool playerStanding;

};
