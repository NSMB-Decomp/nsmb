#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 211  |  ov010  |  profile @ 0x0212704c
class Object211 : public StageEntity {
public:
	static void *create();
	inline Object211() {};
	inline ~Object211() {};
};

extern ActorProfile Object211_Profile;

