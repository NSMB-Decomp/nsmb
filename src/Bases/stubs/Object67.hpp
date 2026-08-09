#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 67  |  ov054  |  profile @ 0x0216d01c
class Object67 : public StageEntity {
public:
	static void *create();
	inline Object67() {};
	inline ~Object67() {};
};

extern ActorProfile Object67_Profile;

