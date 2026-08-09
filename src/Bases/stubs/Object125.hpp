#pragma once
#include "../StageEntity.hpp"

// MainProfileTable slot 125  |  ov117  |  profile @ 0x0218dee0
class Object125 : public StageEntity {
public:
	bool (StageEntity::**_3f4)(u32);
	u8 _pad0[0xc];
	u8 _404;
	u16 _406;
	u8 _pad1[0x4];

	static void *create();
	inline Object125() {};
	inline ~Object125() {};
	static bool loadResources();
	
	bool func_ov117_0218c9b0(u32);

	virtual s32 onCreate();
	virtual s32 onDestroy();
	virtual s32 onRender();
	virtual void pendingDestroy();
	virtual bool onUpdate_0();
};

extern ActorProfile Object125_Profile;

