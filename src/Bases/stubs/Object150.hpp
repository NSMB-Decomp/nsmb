#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"
#include "../../graphics/3d/modelanm.hpp"

// MainProfileTable slot 150  |  ov058  |  profile @ 0x02173680
class Object150 : public StageEntity {
public:
	ModelAnm model;
	u8 _pad0[0x1c];

	static void *create();
	inline Object150() {};
	inline ~Object150() {};

	virtual s32 onCreate();
	virtual s32 onDestroy();
	virtual s32 onRender();
	virtual void pendingDestroy();
	virtual bool onHeapCreated();
	virtual bool onUpdate_0();
};

extern ActorProfile Object150_Profile;

