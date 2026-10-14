#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 143  |  ov025  |  profile @ 0x02141bb8
class Object143 : public StageEntity {
public:
	static void *create();
	inline Object143() {};
	inline ~Object143() {};
};

extern ActorProfile Object143_Profile;

