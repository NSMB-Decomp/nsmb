#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 177  |  ov020  |  profile @ 0x021332f4
class Object177 : public StageEntity {
public:
	u8 _pad0[0x8];

	static void *create();
	inline Object177() {};
	inline ~Object177() {};
};

extern ActorProfile Object177_Profile;

