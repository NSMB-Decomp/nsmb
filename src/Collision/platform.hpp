#pragma once
#include "../Bases/Base.hpp"
#include "../Vec.hpp"

class StageActor;
class Platform;

class PlatformManager
{
public:
	StageActor* owner;
	Vec3_32* linkedPosition;

	PlatformManager* next;
	Platform* head;
	Platform* platform;

	CollisionManager* linkedCollisionMgr;
	u8 _pad1[0x18];

	PlatformManager();
	virtual ~PlatformManager();

	void func_0201d730();
	void init(void *, void *);
};
NTR_SIZE_GUARD(PlatformManager, 0x34);

class Platform {
public:

	enum Type {
		Rotating = 0,
		/* unk1 */
		Segment = 2,
		/* unk2 */
		Deforming = 4,	// used for tightropes
		RoundExternal,	// used by the giant wiggler
		RoundInternal,	// unused
	};

	Platform();
	virtual ~Platform();

	virtual void update();
	virtual void resolveCollision();
	virtual void func5();

	void reset();
	void link();
	void unlink();


	StageActor* owner;

	Platform* prev;
	Platform* next;
	PlatformManager* manager;

	Vec2_32 pointEnd;
	Vec2_32 pointStart;
	Vec2_32 pointStep;
	Vec2_32 lastStart;

	fx32 length;
	fx32 force;

	s16 angle;
	u16 flags;

	u8 type;
	u8 unk51;
	bool linked;
	u8 layerID;

	u8 unk54[4];


	static Platform* listHead;
	static Platform* listTail;

};
NTR_SIZE_GUARD(Platform, 0x58);

struct RotatingPlatformInfo {
	fx32 x;
	fx32 y;
	fx32 height;
	fx32 right;
	fx32 left;
	s16 angle;
	u8 unused;
};

class RotatingPlatform : public Platform {
public:

	RotatingPlatform();
	inline virtual ~RotatingPlatform() {}

	void init(StageActor* owner, fx32 x, fx32 y, fx32 height, fx32 right, fx32 left, s16 angle, u8 layerID, const Vec3_32* scale = nullptr);
	void init(StageActor* owner, const RotatingPlatformInfo& info, const Vec3_32* scale = nullptr);

	void setHeight(fx32 height, fx32 scale);
	void setRight(fx32 right);
	void setLeft(fx32 left);
	void setBase(fx32 left, fx32 right);

	virtual void update() override;

	Vec2_32 center;
	fx32 height;
	fx32 right;
	fx32 left;

};
NTR_SIZE_GUARD(RotatingPlatform, 0x70);

class SegmentPlatform : public Platform {
public:

	SegmentPlatform();
	inline virtual ~SegmentPlatform() {}

	virtual void update() override;
	virtual void resolveCollision() override;
	virtual void func5() override;

	Vec2_32 _58;
	Vec2_32 _64;

};
