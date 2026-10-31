#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 68  |  ov056  |  profile @ 0x02175478
class Object68 : public StageEntity {
public:
	static void *create();
	inline Object68() {};
	inline ~Object68() {};

	void func_ov056_02172e18();
	void func_ov056_021730c0();
	void func_ov056_0217336c();
};

extern ActorProfile Object68_Profile;

// MainProfileTable slot 88  |  ov056  |  profile @ 0x02175484
class Object88 : public StageEntity {
public:
	static void *create();
	inline Object88() {};
	inline ~Object88() {};
};

extern ActorProfile Object88_Profile;

// MainProfileTable slot 89  |  ov056  |  profile @ 0x02175490
class Object89 : public StageEntity {
public:
	static void *create();
	inline Object89() {};
	inline ~Object89() {};
};

extern ActorProfile Object89_Profile;

