#pragma once
#include "../StageEntity.hpp"
#include "../../AAA.hpp"

// MainProfileTable slot 200  |  ov116  |  profile @ 0x0218efc0
class Object200 : public StageEntity {
public:
	static void *create();
	inline Object200() {};
	inline ~Object200() {};
};

extern ActorProfile Object200_Profile;

