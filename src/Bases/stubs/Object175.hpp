#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 175  |  ov086  |  profile @ 0x0217eb60
class Object175 : public StageEntity {
public:
	static void *create();
	inline Object175() {};
	inline ~Object175() {};
};

extern ActorProfile Object175_Profile;

