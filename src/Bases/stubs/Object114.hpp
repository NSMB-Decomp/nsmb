#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 114  |  ov040  |  profile @ 0x02146720
class Object114 : public StageEntity {
public:
	static void *create();
	inline Object114() {};
	inline ~Object114() {};

	void func_ov040_021421cc();
	void func_ov040_02142620();
	void func_ov040_02142f74();
	void func_ov040_02143190();
	void func_ov040_021433c8();
	void func_ov040_02143488();
	void func_ov040_02143550();
	void func_ov040_02143634();
};

extern ActorProfile Object114_Profile;

