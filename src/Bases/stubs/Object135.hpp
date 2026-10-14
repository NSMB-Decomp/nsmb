#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 135  |  ov018  |  profile @ 0x021324f8
class Object135 : public StageEntity {
public:
	static void *create();
	inline Object135() {};
	inline ~Object135() {};
};

extern ActorProfile Object135_Profile;

