#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

class Object160_Unknown {
	public:
	u8 _pad0[0x4];

	Object160_Unknown();
	~Object160_Unknown();
};

// MainProfileTable slot 160  |  ov054  |  profile @ 0x0216e2b0
class Object160 : public Object {
public:
	u8 _pad0[0x8];
	Object160_Unknown _64[5];
	u8 _pad1[0x2c];

	static void *create();
	Object160();
	inline ~Object160() {};

	void func_ov054_0215fea4();

	virtual s32 onCreate();
	virtual s32 onDestroy();
	virtual s32 onUpdate();
	virtual s32 onRender();
};

extern ObjectProfile Object160_Profile;

