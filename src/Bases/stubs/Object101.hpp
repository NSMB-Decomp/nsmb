#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 101  |  ov081  |  profile @ 0x0217b884
class Object101 : public StageEntity {
public:
	static void *create();
	inline Object101() {};
	inline ~Object101() {};
};

extern ActorProfile Object101_Profile;

// MainProfileTable slot 102  |  ov081  |  profile @ 0x0217b890
class Object102 : public StageEntity {
public:
	static void *create();
	inline Object102() {};
	inline ~Object102() {};
};

extern ActorProfile Object102_Profile;

