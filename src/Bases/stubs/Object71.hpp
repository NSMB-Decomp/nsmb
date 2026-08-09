#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 71  |  ov054  |  profile @ 0x02170538
class Object71 : public StageEntity {
public:
	static void *create();
	inline Object71() {};
	inline ~Object71() {};
};

extern ActorProfile Object71_Profile;

